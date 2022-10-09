# Linux性能优化
参见 Linux性能优化

# TODO

参考
Spring Boot+SQL/JPA实战悲观锁和乐观锁
https://segmentfault.com/a/1190000017410662

# 数据库
一些基础数据库知识
Some question about general database knowledge, e.g. shared lock, exclusive lock, dirty read, transaction, 乐观锁，悲观锁

## 乐观锁悲观锁
例如多个用户同时并发在一个短视频评论时，他们需要
1. 拿到ArticleID和评论数字
2. 插入对应的Comment
3. 更新评论数量保存到数据库
由于他们是同时在步骤1拿到的评论数量，所以在第三步更新的评论数+1是错的。

**乐观锁**

乐观锁顾名思义就是特别乐观，认为自己拿到的资源不会被其他线程操作所以不上锁，只是在插入数据库的时候再判断一下数据有没有被修改。所以悲观锁是限制其他线程，而乐观锁是限制自己，虽然他的名字有锁，但是实际上不算上锁，只是在最后操作的时候再判断具体怎么操作。

乐观锁通常为版本号机制或者CAS算法
```
JPA
@Data
@Entity
public class Article {   
    @Version
    private Long version;
}
其它都一样,修改失败直接抛出异常 ObjectOptimisticLockingFailureException
// CommentService
public void postComment(Long articleId, String content) {
    Optional<Article> articleOptional = articleRepository.findById(articleId);
    article.setCommentCount(article.getCommentCount() + 1);
    articleRepository.save(article);
}

或者手动增加column version
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Modifying
    @Query(value = "update article set comment_count = :commentCount, version = version + 1 where id = :id and version = :version", nativeQuery = true)
    int updateArticleWithVersion(Long id, Long commentCount, Long version);
}
```

**悲观锁**
需要查询的时候把该行锁住
使用lock或者SQL中加入FOR UPDATE
```
JPA 
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Lock(value = LockModeType.PESSIMISTIC_WRITE)
    @Query("select a from Article a where a.id = :id")
    Optional<Article> findArticleWithPessimisticLock(Long id);
}

或者Query中手动加入 for update
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Query(value = "select * from article a where a.id = :id for update", nativeQuery = true)
    Optional<Article> findArticleForUpdate(Long id);
}
```

**实践**
一般来说是两步操作,1.取得数据，2 该数据+1(或者其他操作) 3.写回数据库
这个过程需要加锁
如果说直接把数据写回去，好像不需要，写的时候会带锁,不可能出现分别写一列的情况





## 锁
个人认为锁与事务的隔离级别不存在任何关系，但是我们有时候经常被这两个概念弄混淆。
锁与事务隔离级别都是为了保证在多线程并发环境下，数据访问的安全性。当时事务交叉执行时，如果不设置事务的隔离级别(事务存在还有意义吗？)，那么数据将会被不同事务轮访问和修改，执行结果无法预期。

读锁（共享锁）：相互不阻塞，可以在同一时刻读取同一个资源，即在同一个资源上可以同时添加多个读锁。
写锁（排他锁）：阻塞其他读锁或写锁，独占资源，在给定的时间内只允许一个用户写入。
锁粒度：加锁对象（资源）的大小。锁粒度的大小影响的系统的并发性和系统开销。当锁粒度较小，可以提高资源的并发使用，但是也增加的系统加锁的开销。反之，锁粒度越大，并发度越低，
表锁（table locks）：在整张表上进行加锁，如MyISAM引擎。
行锁（row locks）：在表中的一行或者多行数据记录上加锁。
页锁（page locks）：目前只有BDB存储引擎使用。
元数据锁（Metadata Locks）：MySQL5.5中引入，应用在表的metadata上。当一个线程使用表的时候，将会锁定整张表的metadata信息，不允许其他线程修改表结构。


1、加锁与解锁时机：当开始执行SQL，将会对一些数据进行加锁，如整个表，某些行，metadata信息。当sql执行完成，将会解锁，其他线程就可以开始申请使用资源。
2、MySQL事务特性是由存储引擎提供的，如常用的InnoDB。一个事务由一个或者多个SQL组成，事务的隔离性进一步确保在多线程并发环境下数据的安全访问，直接决定事务中sql修改的数据在提交之前是否对其他事务是否可见。



# 数据密集型应用 / 高并发
这里有很多东西，确实可以结合AWS写一下，包括trust bank的实践
- 使用缓存和数据库时带来的同步问题
- 使用HA cluster时遇到的脑裂问题

## c5数据复制
aws rds 主从同步复制，只读副本异步复制
但是postgres,mysql等主从复制 是异步，这样master无需等待slave, MySQL5.5半同步，保证至少一个slave复制
kafka的leader+follower有所不同，ack是同步等待的

DDIA 指出
同步复制 - 单点故障导致整个同步失败
异步复制 - 是一个不太靠谱的实现，缺点为副本的滞后问题,以及如果主节点失效，而所有从节点都没有更新数据
半同步 - 一个节点是同步复制，另外的是异步

现实
AWS RDS multi-az, 一个standby节点采用同步复制，用于做primary的备份，别的只读副本采用异步复制方式，正好就是半同步方式
由于异地多活这种地理环境的影响，很多数据库还是采用异步复制的

主节点失效
AWS RDS从standby提升为主节点，这个保证是同步的

### 复制日志的实现
- 语句, 用户自定义的函数有副作用
- WAL预写日志，这个在磁盘块level
- 基于行的逻辑日志复制，复制和存储的逻辑分离(binlog)
- 触发器的复制

### 场景
**写后读**
- 可能被修改的内容，从主节点读，否则从只读副本;

- 如果无法做到这点，则需要更多的应用层方案解决，比如最近更新时间（版本号）或者客户端带上要求的最新时间
但是一般客户端配置的是固定的read-replica,如何在不同的read-replica切换？需要客户端实现
实际上知道最新时间戳也有难度，如果是在另一台设备上更新数据 => 基本上只有通过一个全局节点/元数据(即primary node)

**单调读**
即保证每一次读必须在上一次读之后，不允许数据回滚。解决=>从固定的一个副本读取


**前缀一致读**
写入的顺序和读出的顺序保持一致，但是如果是multi-master的数据库，就不存在固定的写入顺序
一般通过单primary来解决

**多主节点同步**
AWS aurora采用的是底层存储分成多块，不仅是同一行，写到同一块的数据都会造成冲突，这个冲突交给应用层来解决
多主节点multi-master没有所谓的faiover，因为所有节点都可以写
multi-master一般用于multi-region的方案，即用户只读取离自己近的数据中心

DDIA的多主节点同步解决方案
基于时间戳，最后写入者作为最终数据；合并串联所有写入数据,按优先级/ID来决定谁写入有效=>丢失数据

由应用层来解决：
使用事务,对于银行等交易
保存所有写入数据，然后在读取时全部返回给用户

并发写还有些补充
- 不保存所有写，只有先写入的成功，其它的返回失败
- 最后写入获胜，丢弃其它(不合理)

基于版本号的写入，从而指导依赖关系


**无主节点复制**
dynamodb 所有副本可以接受客户的写请求？
设想,客户==>写到所有副本1,2,3(down)， 从所有副本读取，从而发现某些副本的版本号比较新(rocksdb的额外实现？)


**quorum**
节点失效之后的修复
n（个数）,w,r之类的配置，来法定读或写是否有最新值/成功的仲裁?
在dynamo系列的数据库中采用 sloopy quorum, Riak,cassandra,Voldemort


## c6 数据分区

## c7 事务
**ACID**
原子性 一致性 隔离性 持久性
DDIA 中认为ACID有点像营销概念
- 原子性 客户端一个写操作包括多个步骤，如果其中一个失败时如何看待.基本上者需要数据库给出什么操作是原子性，没有中间状态
- 一致性，通过原子性，隔离性来达到一致性。这是应用层的概念，C不应属于ACID

### 弱隔离级别导致企业审计问题
首先
1. 未提交读(Read Uncommitted):事务中的数据修改，即使事务未提交，对其他事务也是可见的。事务可以读取未提交的数据，也称为“脏读”。
其实根本不算是一种隔离级别，它属于无隔离

**1. 读-提交**
最基本的隔离级别， =>等同于下面的2, oracle, postgres, SQLserver, MemSQL, MySQL default配置
实现:
维护一个旧的值和当前正在修改的事务的新值

**2. 快照级别隔离**
有点像可重复读
阻止同一对象上的其它事务操作， 但是是真的阻止还是只是单纯的忽略？
实现，使用MVCC，保存了多个版本
事务开始时，列出所有进行中的事务id，而较晚事务的id全部被忽略

**如何索引MVCC多版本数据**
- 追加btree
- postgres保存在同一页

**解决并发写的问题**
参考前面的乐观锁悲观锁， 例如两个医生同时请假造成无人值班问题=>事务施加在多对象上

**3. 串行化**
靠应用层/事务无法解决时
通过存储过程来实现,但是每家都有自己的存储过程语言:oracle PL/SQL, SQLSERVER T-SQL, postgres PL/pgSQL
现在 redis->lua, voltdb->java/Groovy, Datomic->java/Clojure

对数据分区，即水平扩展
支持跨区事务，但是占比很小

### 四种隔离级别
参考
https://blog.csdn.net/fanrenxiang/article/details/102650127

级别
 1. 未提交读(Read Uncommitted):事务中的数据修改，即使事务未提交，对其他事务也是可见的。事务可以读取未提交的数据，也称为“脏读”。
 2. 提交读(Read Committed)：事务开始时，只能看见已提交事务的修改。换句话说，一个事务从开始到提交之前，所作的任何操作对其他事务是不可见的。但是如果在事务执行过程中，有其它事务提交修改，那么前后两次读取相同记录的结果不相同（不一致），也称作不可重复读（nonrepeatable read）受其他事务影响
 
 3. 可重复读(Repeatable Read)：事务中前后两次读取相同记录的结果是一致的，即使有事务提交。(不受别的事务提交的影响)。可重复读可以解决脏的问题，但是存在幻读（Phantom Read）的问题:当事务在读取某个范围内记录的时候，如果另外一个事务插入了新的数据记录，之前的事务中再次读取该范围内的数据记录，那么将会产生幻行（Phantom Rows）。或者幻读问题。 
 ==>解决： InnoDB通过使用多版本并发控制MVCC解决了幻读的问题。

 4. 可串行化(Serializable)：事务串行化执行。


常见的几个问题解决方案
1. 脏读 ->1 使用 提交读隔离级别
2. 不可重复读  ->2提交读隔离级别, 开启事务后会看到2次不同的结果,事务A在事务B提交前后读取到不一样的数据,
3. 幻读 -> 幻读是事务非独立执行时发生的一种现象。例如事务T1对一个表中所有的行的某个数据项做了从“1”修改为“2”的操作，这时事务T2又对这个表中插入了一行数据项，而这个数据项的数值还是为“1”并且提交给数据库。即T2并不知道数据库的版本已变更
解决： MVCC 3 多版本。 (与2相比侧重于innsert/delete操作)
4. 何为幻行?


### 两阶段加锁
2PL =>2 phase lock
有点像第二阶段，要修改的话必须把锁提升到写锁, 性能问题

谓词锁 - 作用在某些条件下的对象
索引区间锁, 如以时间为条件， 将锁挂到索引上-> select from where xxx for update??

### 可串行化的快照隔离
是一种乐观并发控制，在提交时检查某些外部依赖数据是否已被更改


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




