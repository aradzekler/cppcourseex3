#pragma once
#ifndef MEMBER
#define MEMBER
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Member {
private:
    string name;
    int id; // unique object id.
    vector<Member*> followingList; // vectors hold following and followers.
    vector<Member*> followersList;
public:
    static int memberCount; // static for counting total objects.
    static int idCounter; 
    static int count();
    static list<int> onlineUsers;
    Member();
    ~Member();
    void follow(Member &member);
    void unfollow(Member &member);
    int numFollowing();
    int numFollowers();
};

#endif 
