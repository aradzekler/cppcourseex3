#include <iostream>
#include <map>

using namespace std;

static int memberCount = 0;

class Member {
private:
    map<string, Member> followingList;
    map<string, Member> followersList;
public:
    string name;
    Member() {
        followingList;
        followersList;
        this->name = name;
        memberCount++;
        }
    ~Member() {
    }


// follow another member.
void follow(Member &member) {
    if (followingList.find(member.name) != followingList.end()) {
        return;
    }
    else {
        followingList.insert(make_pair(member.name, member));
        member.followersList.insert(make_pair(this->name, member)); // adds this name to members followers list.
    }
}

//unfollow another member
void unfollow(Member &member) {
    if (followingList.find(member.name) != followingList.end()) {
        followingList.erase(member.name);
        member.followersList.erase(this->name);
    }
}

// return number of members this one is following.
int numFollowing() {
    return followingList.size();
}

// returns number of followers.
int numFollowers() {
    return followersList.size();
}

static int count() {
    return memberCount;
}

    
};
