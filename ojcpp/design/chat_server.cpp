//
// Created by rui.zhou on 3/17/2019.
//

/*
 *  先考虑实现的功能
 *  user login
 *  add/reject.approve friend request
 *  send chat (private & group)
 *  userstatus
 */
#include <codech/codech_def.h>

using namespace std;
namespace {
    enum RequestStatus {
        UNREAD,
        READ,
        ACCEPT,
        REJECT
    };
    enum UserStatus {
        AWAY,
        OFFLINE,
        IDLE,
        BUSY,
        AVAILABLE
    };

    struct AddUserReq {
        int ts_;
        int from_;
        int to_;
        RequestStatus status_;
    };
    struct Message {
        int mId_;
        string content_;
        int ts_;
        Message() {}
    };

    class Chat {
    protected:
        vector<Message> msgList_;
    public:
        virtual void sendMsg() = 0;
        virtual void recvMsg() = 0;
    };

    class P2pChat :public Chat {
    public:
        virtual void sendMsg(){}
        virtual void recvMsg(){}
    };

    class GroupChat :public Chat {
    public:
        virtual void sendMsg(){}
        virtual void recvMsg(){}
    };
    class User {
    protected:
        int uid_;
        string name_;
        unordered_map<int, AddUserReq> sendReq_;
        unordered_map<int, AddUserReq> recvReq_;
        unordered_map<int, User*> contacts_;
        unordered_map<int, P2pChat*> privateChats_;
        unordered_map<int, GroupChat*> groupChats_;
    public:
        User(int, string) {}
    };

    class ChatServer {
        unordered_map<int,User*> userMap_;
    public:
        bool login(User &user) {return true;}
        bool logout(User &user) {return true;}
        void addUser(User &from, User &to){}
        bool rejectAddUser(){return true;}
        bool approveAddUser(){return true;}

    };






}