#include <iostream>
#include <map>
#include "Member.h"
using namespace std;

int Member::memberCount = 0;


Member::Member() {
    followingList = new map<string, Member>;
    followersList = new map<string, Member>;
    memberCount++;
}


Member::~Member(){
        memberCount--;
        //this->followingList->clear();
        //this->followersList->clear();

}

void Member::follow(Member &member) {
    if (this->followingList->find(member.name) != this->followingList->end()) {
        return;
    }
    else {
        this->followingList->insert(make_pair(member.name, member));
        member.followersList->insert(make_pair(this->name, member)); // adds this name to members followers list.
    }
}

void Member::unfollow(Member &member) {
    if (this->followingList->find(member.name) != this->followingList->end()) {
        this->followingList->erase(member.name);
        member.followersList->erase(this->name);
    }
}

// return number of members this one is following.
int Member::numFollowing() {
    return this->followingList->size();
}

// returns number of followers.
int Member::numFollowers() {
    return this->followersList->size();
}

int Member::count() {
    return memberCount;
}
