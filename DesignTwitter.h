class Twitter {
private: 
    int _tweet_count;
    unordered_map<int, unordered_set<int>> _following;
    unordered_map<int, vector<pair<int,int>>> _tweets;

public:
    Twitter() : _tweet_count(0) {}
    
    void postTweet(int userId, int tweetId) {
        _tweets[userId].push_back({_tweet_count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news_feed;
        priority_queue<pair<int,int>> pq;

        for(auto &tweet : _tweets[userId])
            pq.push(tweet);

        for(auto &followee : _following[userId])
            for(auto &tweet : _tweets[followee])
                pq.push(tweet);
    
        while(!pq.empty() && news_feed.size() < 10) {
            news_feed.push_back(pq.top().second);
            pq.pop();
        }
    
        return news_feed;
    }
    
    void follow(int followerId, int followeeId) {
        _following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        _following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
 
 //https://leetcode.com/problems/design-twitter/