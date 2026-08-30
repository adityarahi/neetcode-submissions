class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int ts; // timestamp;

    Twitter() {
        ts = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        ts++;
        tweets[userId].push_back({ts, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sz = tweets[userId].size();
        for(int i = sz - 1; i >= max(0, sz - 10); i--) {
            pq.push(tweets[userId][i]);
        }
        for(auto& follow_id : following[userId]) {
            sz = tweets[follow_id].size();
            for(int i = sz - 1; i >= max(0, sz - 10); i--) {
                pq.push(tweets[follow_id][i]);
                if(pq.size() > 10) pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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