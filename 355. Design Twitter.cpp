/*
  要設計一個能夠發推，追蹤/取消追蹤別人，並且顯示他的10條 feed 的推特系統。
  先建立一個 Tweet 的 class，一個tweet裡會有：
  - id, 也就是 tweetId
  - time, 也就是 timeStamp
  - next, 指向下一個 tweet, 建成一個linked list

  為了要方便管理不同 user id 發過的 tweet，另外再建立一個 User 的 class
  裡面存有： (1) id, 也就是 userid, 
  (2) follows, 一個 unordered_set 用來存這個 user 有 follow 的其他 userid,
  (3) tweets, 一個 Tweet 的 linked list, 存自己發過的 tweet
  (4) follow/unfollow 的 method, 就對follows這個結構做操作而已
  (5) post 的 method, new 一個 tweet 出來, 將他的 next 接到 目前的 tweets
  (6) **初始化的時候會 follow 自己**
  
  有了這兩個 class 後就能開始處理 Twitter 的 design:
  - postTweet: 就呼叫該名user的post, 注意user不存在的話要新增一個
  - follow/unfollow: 同上, 但要注意user存不存在, 而且不能 unfollow 自己
  - getNewsFeed: 關鍵, 用 priority_queue 存 tweets, 根據timeStamp排序,
    把follow的users的tweet都往裡面扔，然後反覆取出放到feed再放next進去這個動作，
    最多十次。

*/
class Tweet {
public:
    int id,time;
    Tweet* next;
    Tweet(int i, int t):id(i), time(t), next(NULL){}
};

class User {
public:
    int id;
    unordered_set<int> follows;
    Tweet* tweets;
    
    User() {}
    
    User(int i) {
        id = i;
        tweets = NULL;
        follow(i);
    }
    
    void follow(int userID) {
        follows.insert(userID);
    } 
    
    void unfollow(int userID) {
        follows.erase(userID);
    }
    // make the new tweets be the head of the list
    void post(int tweetID, int time) {
        Tweet* cur = tweets;
        tweets = new Tweet(tweetID, time);
        tweets->next = cur;
    }
};

class Twitter {
private:
    int timeStamp = 0;
    unordered_map<int, User> users;
    struct compare {
        bool operator() (const Tweet* a, const Tweet* b) {
            return a->time < b->time;
        }
    };
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!users.count(userId)) 
            users[userId] = User(userId);
        users[userId].post(tweetId, timeStamp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        if(!users.count(userId)) {
            return feed;
        }
        unordered_set<int> userIds = users[userId].follows;
        priority_queue<Tweet*, vector<Tweet*>, compare> pq;
        for(int userId : userIds) {
            Tweet* tweets = users[userId].tweets;
            if(tweets)
                pq.push(tweets);
        }
        int loop = 10;
        while(!pq.empty() && loop--) {
            Tweet* tweets = pq.top();
            pq.pop();
            feed.push_back(tweets->id);
            if(tweets->next)
                pq.push(tweets->next);
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!users.count(followerId))
            users[followerId] = User(followerId);
        if(!users.count(followeeId))
            users[followeeId] = User(followeeId);
        users[followerId].follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(users.count(followerId) && users.count(followeeId) && followerId!=followeeId)
            users[followerId].unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */