#pragma once
#ifndef MEMBER
#define MEMBER
#include <iostream>
#include <map>
using namespace std;

class Member {
private:
    string name;
    static int memberCount;
    map<string, Member> *followingList;
    map<string, Member> *followersList;
public:
    Member();
    ~Member();
    int numFollowers();
    int numFollowing();
    void follow(Member &member);
    void unfollow(Member &member);
    static int count();
};

#endif 
