#pragma once
#ifndef MEMBER
#define MEMBER
#include <iostream>
#include <vector>
using namespace std;

class Member {
private:
    string name;
    vector<Member*> followingList; // vectors hold following and followers.
    vector<Member*> followersList;
public:
    static int memberCount; // static for counting total objects.
    static int count();
    Member();
    ~Member();
    void follow(Member &member);
    void unfollow(Member &member);
    int numFollowing();
    int numFollowers();
};

#endif 
