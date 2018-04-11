#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "Member.h"
using namespace std;

int Member::memberCount = 0;
int Member::idCounter = 0;

int Member::count() {
    return memberCount;
}

Member::Member() {
    id = ++memberCount;
    idCounter++;
    onlineUsers.push_back(memberCount);
    memberCount++; // every obj creation adds to counter.
}

Member::~Member(){
    onlineUsers.remove(id);
    memberCount--;
}

void Member::follow(Member& member) {
       if (find(followingList.begin(),followingList.end(), member.id) == followingList.end()) {
            followingList.push_back(member.id);
            member.followersList.push_back(id);
     }
}

// unfollows (takes care of both lists)
void Member::unfollow(Member& member) {
    for (int i = 0; i<followingList.size(); i++) {
        if(followingList[i] == member.id) {
            followingList.erase(followingList.begin() +i); 
        }
    }
    for (int i = 0; i<member.followersList.size(); i++) {
        if (member.followersList[i] == id) {
            member.followersList.erase(member.followersList.begin() +i);
        }
    }
}

// return number of members this one is following.
int Member::numFollowing() {
       for (int i=0;i<followingList.size();i++) {
        list<int>::iterator it;
        it= find(onlineUsers.begin(), onlineUsers.end(), followingList[i]);
        if (it == onlineUsers.end()){
            followingList.erase(followingList.begin()+i);
        }
    }
    return followingList.size();
}

// returns number of followers.
int Member::numFollowers() {
    for(int i=0;i<followersList.size();i++) {
        list<int>::iterator it;
        it= find(onlineUsers.begin(), onlineUsers.end(), followersList[i]);
        if(it == onlineUsers.end()) {
            followersList.erase(followersList.begin()+i);
        }
    }
    return followersList.size();
}

