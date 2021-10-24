/* 思路：类似合并K个有序链表，每个人发的推文可看作一个链表 */

struct Tweet {
    int id;
    int index;
    Tweet(int id, int index) : id(id), index(index) { }
};

struct Person {
    vector<Tweet> tweet;
    unordered_set<int> follow;
};

struct Node {
    Person *person;
    int pos;
    Node(Person *a, int b) :person(a), pos(b) { }
};

bool operator < (Node a, Node b) {
    return a.person->tweet[a.pos].index < b.person->tweet[b.pos].index;
}

class Twitter {
public:
    Twitter() {
        index = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Person *p = getUser(userId);
        p->tweet.push_back(Tweet(tweetId, index));
        index++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (users.find(userId) == users.end()) {
            return {};
        }
        Person *p = users[userId];
        priority_queue<Node> que;
        for (int followId : p->follow) {
            if (users.find(followId) != users.end()) {
                auto temp = users[followId];
                if (temp->tweet.size() > 0) {
                    que.push(Node(temp, temp->tweet.size() - 1));
                }
            }
        }
        /* 加入自己 */
        if (p->tweet.size() > 0) {
            que.push(Node(p, p->tweet.size() - 1));
        }
        vector<int> ans;
        while (!que.empty() && ans.size() < 10) {
            auto t = que.top();
            que.pop();
            ans.push_back(t.person->tweet[t.pos].id);
            if (t.pos - 1 >= 0) {
                que.push(Node(t.person, t.pos - 1));
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        Person *p = getUser(followerId);
        p->follow.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        Person *p = getUser(followerId);
        p->follow.erase(followeeId);
    }
private:
    Person *getUser(int userId) {
        Person *p;
        if (users.find(userId) == users.end()) {
            p = new Person();
            users[userId] = p;
        } else {
            p = users[userId];
        }
        return p;
    }

    unordered_map<int, Person *> users;
    int index;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */