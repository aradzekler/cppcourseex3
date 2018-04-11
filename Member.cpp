#include <iostream>
#include <vector>
#include "Member.h"
using namespace std;

int Member::memberCount = 0;

int Member::count() {
    return memberCount;
}

Member::Member() {
    memberCount++; // every obj creation adds to counter.
}

Member::~Member(){
    memberCount--;
}

void Member::follow(Member &member) {
    for(int i =0; i < followingList.size(); i++) {
       if ((followingList[i]->name) == (member.name)) { // if already exists.
        return;
         }
    }
    followingList.push_back(&member);      // add to lists.
    member.followersList.push_back(this);
}
// unfollows (takes care of both lists)
void Member::unfollow(Member &member) {
    for (int i = 0; i < followingList.size(); i++) {
        if(followingList[i] == &member) {
            followingList.erase(followingList.begin()+i);
            break;
        }
    }
    for(int i = 0; i<followersList.size(); i++) {
        if(followersList[i] == &member) {
            followersList.erase(followersList.begin()+i);
            break;
        }
    }
}

// return number of members this one is following.
int Member::numFollowing() {
    return followingList.size();
}

// returns number of followers.
int Member::numFollowers() {
    return followersList.size();
}
