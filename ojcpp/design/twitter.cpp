//
// Created by rui zhou on 18/03/19.
//

// timeline -
//  home
//  user
// story/user case
// 用户发表一个tweet
// 自己发表一个
//table --
// user table :uid,name, information
// tweet table: tid,content, uid,
// follower table: uid, followerid

// 更关注availablity, less consistency, eventually consistency
// 即尽快让别人看到你的tweet

// home timeline 流程 1.get folllowing id list;2.get tweet content from table where uid=following id;3.render html

// LB(nginx/haproxy/cloud) - app server - redis cluster
//                                      -- mysql


// 操作分为 read 读取tweet ; write - 发送tweet
// 如何解决有大量follower的tweet

//模块分为 user, comment, msg, feeds, tweet
namespace {
    class Tweet{};
    class User{};


}