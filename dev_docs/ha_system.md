# Linux性能优化
参见 Linux性能优化

# TODO

参考
Spring Boot+SQL/JPA实战悲观锁和乐观锁
https://segmentfault.com/a/1190000017410662

乐观锁，悲观锁



# 数据密集型应用 / 高并发
这里有很多东西，确实可以结合AWS写一下，包括trust bank的实践
- 使用缓存和数据库时带来的同步问题
- 使用HA cluster时遇到的脑裂问题


## rabbitMQ/aerospike脑裂 split brain
not used in WAN, use shovel or federation,解决，
使用ignore,autoheal(AP)重启客户端连接最少的分区，有状态丢失，pause_minoity(停止分区少于一半节点的集群)，CP
所谓的脑裂问题，就是在多机热备的高可用 HA 系统中，当两个节点心跳突然断开，就分裂为了两个独立的个体，由于互相失去联系，都认为对方出现了故障，因此都会去争抢对方的资源，争抢启动，由此就会发生严重的后果。

可以认为这是某些HA系统自身不完善，或者部署方式有问题跨wan导致延时过大。



## 负载均衡
这应该是个成熟的架构,AWS LB(nginx)+ASG+TARGET, EKS, Cloudfronnt,
EKS 使用 cluster autoscaler
讲讲亿级PV的负载均衡架构
https://zhuanlan.zhihu.com/p/61847281
这里提到的是一个DNS+LVS, 在4层做负载均衡的架构，==>AWS network load balancer




缓存
分流
消息队列
限流


## 服务治理
## 分布式trace, 
- 加入traceID，或者PCF自带带traceID
- 使用APM工具
- AOP 来拦截

## 配置管理
spring cloud config
disconf,apollo

## 降级熔断,限流
resilience4J
hysterx
滑动窗口限流，用户id,key，令牌桶

# 全链路压力测试
流量产生，流量隔离，标记数据（染色）
第三方服务mock
影子存储
流量监控



## 如何做负载均衡 - 海量PV(亿级) 
不考虑kubernetes的话，先看loadbalance
- vertical 更强的机器; horizontal - 更多的同类机器
- DNS(无法保证可用性，不知道server dead), 
- VRRP(将多个server映射到同一个Ip), LVS(4层)集群,
- nginx(7层)  ->backend server
- 从客户端做，不妥

## 策略
- robin
- hash
- 动态数据，比如负荷,leastactive，响应时间作为权重

## 故障
nginx check module
- eureka  无session要求 ->AP
- zookeeper -> CP，主要是election leader和分布式锁
- haproxy  

2. 通过kubernetes 高可用 - rancher kubernetes engine RKE方案/或者云厂商 TODO

### 数据迁移
双写，灰度部署


## 缓存/Redis
**LRU 实现**
hashmap， key-value(value和ptr指向timelist）
timelist，按时间排列，每次访问后，挪到list头部，同时更新hashmap中的指针
redis内置了近似LRU算法，能够直接从hashmap中把过期key拿出来

**原子操作/分布式锁**
类似于CAS操作，如果值=x那么改为y, setnx，但实现麻烦，有redlock,redisson
使用lua脚本,把两个操作合并为原子操作，参考seatalk

### 缓存雪崩
原因 缓存失效，都去访问数据库了，造成一系列连锁反映
解决 排队，服务降级

### 缓存穿透
也是一种缓存失效，更多表现为缓存命中率差，多数没有命中，直接去访问数据库，结果数据库里也没有
解决 使用bloomfilter来把一些肯定不在数据库里的直接拦掉
也可以数据库没有，依旧创建一个空缓存，过期时间5分钟(如果数据库双写的话就无所谓，反正同时更新)

即缓存没有起到作用，直接穿透到后端的数据库了，比如说查询一个不存在的用户，缓存中没有，数据库中也没有，
解决办法，
1. 使用bloom filter，可以在缓存那里挡一下，判断某个data在不在数据库里
缺点，假阳性，判断元素在集合里，实际不在，但是如果判断不在，那肯定不在
2. 可以在缓存里写一个空值或标志

### 缓存的高可用
- 客户端方案 一致性hash算法，较难维护
- 中间代理层 twemproxy, codis, mcrouter,均处于淘汰状态
- 服务端方案 redis sentinel, cluster


### 如何保持mysql和redis中数据的一致性？
**策略**
- cache aside; 更新数据库后删除缓存 (又叫实时策略)
- write through,由缓存来更新数据库
- CDC,由binlog来回写数据库

如何在cache和database之间做同步

背景
比如用户信息数据存储在mysql, 用redis 做缓存，当修改了用户信息，怎么样保证缓存中的数据也被更新？

- update cache, then database, 这个方案很差，假如写数据库失败，则丢失数据
- double write, write database then cache. -> 可能写cache 故障失败；也可能多个用户写造成竞态，必须用个分布式锁
- cache aside, update database, invalid cache； 

**实时策略**
实时策略是最常用的策略，也是保持实时性最好的策略：
读取的过程，应用程序先从 cache 取数据，没有得到，则从数据库中取数据，成功后，放到缓存中。如果命中，应用程序从 cache 中取数据，取到后返回。

写入的过程，把数据存到数据库中，成功后，再让缓存失效，失效后下次读取的时候，会被写入缓存。
为什么写入过程不直接写缓存: 如果想本次同步写缓存，则需要一个分布式锁，保证数据库里写的也是同一个东西，太复杂

缺点:慢， DB更新后使缓存失效。然而，这和第三个问题（高并发）就矛盾了——如果所有的都实时从数据库里面读取，高并发场景下，数据库往往受不了。

变种:
redis设置失效时间，写DB后，不更新redis，让它自然失效(cache aside)，
总结：
但是,从用户体验的角度，应该数据库有了写入，就马上废弃缓存，触发一次数据库的读取，从而更新缓存。(为什么不用该数据直接更新缓存-这需要数据库客户端写缓存了，其实也是可以的)
如果设置失效时间， 这不好设定，而且浪费

**CDC, binlog回填**
change data capture  我觉得这个更好，由数据库回填
实际上目前更加流行的做法是用CDC的方式来做。CDC，即Change Data Capture，主要思想是将数据库的每次变更追加写入到一个日志中，然后让Redis按照日志中的变更顺序重演一遍更新操作，这样就能保证Redis与数据库保持同步。CDC基本的思想就是让你的权威数据源（通常是数据库）成为leader副本 ，让其他的异质系统（不仅是Redis，也可以是ES、数仓等）成为follower副本，通过基于日志（log-based）的CDC机制保证leader与follower之间的同步。好消息是目前越来越多的数据库天然地提供CDC的接口或API供外部系统调用。(例如binlog?)

变种:
1. 由DB侧代码负责写完DB后更新redis,叫做业务双写（可以通过队列之类的完成）,但是无法解决多个客户端多些redis造成的问题
2. 由客户端双写的话需要使用paxos或者raft(zookeeper/redisson)分布式锁进行双写.这个耦合性太大，需要各个客户端代码修改

**唯一数据源**
某种场合需要强一致性，这个干脆就用一个数据源
比如12306,就存在车票信息和真实情况存在一定的差异，需要另外同步

参考
https://www.zhihu.com/question/319817091



# Kafka 
1. 一个kafka cluster可以有多个broker,zookeeper
2. 每个topic可以有多个分区partition,每个分区就如同一个无限长度的顺序数组,同一个topic的分区可以放到不同的broker上面
3. producer可以将数据写到多个broker的多个partition的,不指定的话就是使用RR
4. 多个consumer也可以并发的从多个partition读，实现负载均衡和水平扩展
5. kafka 维护着一个partition中该条消息的offset
6. consumer rebalance - 每个新增加的consumer／broker，需要重新调整所在group里已有的consumer对应的分区，以达到平衡
7. kafka对存储，网络一块有优化，例如cache,page，因此性能很高

**问题**
consumer是否连接到组内所有的partition?不是的话就有可能丢消息了
->client会连接到按照ISR列出的所有leader？不指定partiton的话,broker有一个动态的partiton list,会把list内的partition所有消息发给client.(见下)

如果多个consumer 属于同一个group, client会否只链接某个partiton,broker会根据链接情况动态给client分配partiton ?从而造成consumer收不到所有消息（这仿佛是合理的，确实需要每条消息只被处理一次)
同一个group下的不同consumer，不能访问同一个partition,换言之，C1->P1,C2->P2，为了提高吞吐量

如果一条消息要被多个消费者消费的话，必须在不同的group里，(对访问哪个partition没有规定)

所有的partition都必须保证被某一个consumer消费，不存在没有consumer链接的partition


## 投递可靠性
消息的确认方式有3种
- leader确认
- 不确认
- leader和follower都确认，
kafka并非严格的JMS系统，可能消息发送失败（如果不重发），被发送多次。

根据 Kafka 官方文档说明，Producer 发送消息持久化到 Kafka 得到 ack 的回馈这段过程中，基于性能的考虑，Kafka 并没有及时把数据落盘的，而是将数据放到内存（FS cache）中，并周期性的落盘（从磁盘监控也可以看的出来），如果数据未及时落盘，如遇到服务器断电宕机，则数据丢失；
kafka存在消息丢失的可能

## 保证消息只被消费一次
消费可靠性,参见投递可靠性，使用集群,ISR ack，但还是可能突然断电，在处理前丢失
退而其次，保证处理程序幂等，例如使用版本号
客户端， at least once的消费方式，consumer需要自己维护offset,commit，但是不在乎重复消费的话，以换取最大性能


**冗余**
replication-factor，一般等于broker数量？多个副本保证消息不丢失
分区P0，有leader-P0和Follower-P0共两个副本，位于不同的broker上，leader收到消息后，follower需要负责同步,leader挂了,follower要变成leader
如果一个副本落后太多（条数+超时），会从ISR列表中踢出去，但是跟上的话，又能加进来


**消息的顺序性**
如果每条消息有key，那么可以保证它发往同一个partition，而且max.in.flight.requests.per.connection=1,从而保证顺序
但如果有多个partition的时候，无法保证消息的顺序性，consumer可能同时连接多个partition，那一个先收到消息无法确定,但是可以保证单partition有序


**设计**
最优consumer group下的consumer thread的数量等于partition数量，这样效率是最高的。
partition数量取决于消费者,得能被消费者整除，C1->p0,p1;C2->p3,p4


**和AMQ的区别**
AMQ有个BET过程，多个client竞争一个消息
https://zhuanlan.zhihu.com/p/61847281

## 性能
使用监控消息来测量
并发处理消息，但是不要多于一个客户连接同一个分区







# System Design
## tinyurl
https://www.zhihu.com/question/29270034/answer/46446911
难以存在一个hash算法把所有的长地址转换为短地址，因此只能通过unique id来实现(mysql的自增ID)，每来一个长网址，分配一个id，然后把这个id翻译成短网址。
几个问题

1. 如何保证发号器的大并发高可用_ 上面设计看起来有一个单点，那就是发号器。如果做成分布式的，那么多节点要保持同步加1，多点同时写入，这个嘛，以CAP(一致性，可用性，分区容错性)理论看，是不可能真正做到的。其实这个问题的解决非常简单，我们可以退一步考虑，我们是否可以实现两个发号器，一个发单号，一个发双号，这样就变单点为多点了？依次类推，我们可以实现1000个逻辑发号器，分别发尾号为0到999的号。每发一个号，每个发号器加1000，而不是加1。这些发号器独立工作，互不干扰即可。而且在实现上，也可以先是逻辑的，真的压力变大了，再拆分成独立的物理机器单元。1000个节点，估计对人类来说应该够用了。如果你真的还想更多，理论上也是可以的。

3. 10进制到62进制转换
4. 如何保证同一个长网址能得到同样的短网址 - 我的方案是：用key-value存储，保存“最近”生成的长对短的一个对应关系。注意是“最近”，也就是说，我并不保存全量的长对短的关系，而只保存最近的。比如采用一小时过期的机制来实现LRU淘汰。

301 永久重定向
302临时重定向

## 发号器
snowflake
### 高并发写/分布式锁
以上面的发号器为例
有一个全局唯一计数器，N0-N9 一共10个发号器，每次发号器需要递增全局计数器，然后把计数返回给用户
变通的办法上面有讲
 
 
另一个例子，电商系统
[https://zhuanlan.zhihu.com/p/73807097](https://zhuanlan.zhihu.com/p/73807097)
库存的修改
通过分布式锁实现
redis - 通过Redisson实现比较好（底层还是走lua） 性能较好
zookeeper - znode,创建最小序号的临时节点表明获得锁，健壮，但是对ZK集群压力大


## 秒杀系统
[https://www.zhihu.com/question/27894855](https://www.zhihu.com/question/27894855)
加速 静态资源上CDN
前端拒绝／转到静态服务器过滤一大部分 ，限流IP,同一用户
做好容量规划，商品数据库分库分表降低压力
使用消息队列／内存队列保存请求，直接从队列里拿前n个，削峰填谷
容量规划，不同商品，不同的集群，队列
服务降级，可以延后处理订单

参见下面缓存雪崩


## weibo 时间线
计数系统
评论数，点赞数，粉丝数
weibo_id 分库分表,如果容量限制可以分为冷热存储
redis 做计数组件，定制，例如用rocksdDB的TIDB，pika
MQ做削峰，合并消息，批处理

### 未读数
共享的
- 可以使用时间戳，对比后端系统时间
信息流
- redis记录每个用户的post个数，以及自己的已读个数，不太好???

### 微博/抖音 关注设计
如何展示新的评论
把好友的评论放在第一位
通知follower我有新的更新





# 分布式理论
数据分布方式、Lease机制、日志技术、两阶段提交、CAP理论、Quorum机制
hadoop相关（专家级，一般是开放式的）
比如：

分析时数据倾斜了怎么办？
hdfs写的链路是啥？
集群的利用率不高，为什么？怎么调查？
hbase二级索引是咋回事情？
数据高可靠，服务高可用怎么做？
system占用率比较高，一般啥原因？
如果让你设计一个spark，你打算怎么设计？
流式计算怎么流控？
实时计算与离线怎么混合部署？
一车分布式理论的知识？




