class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> posts;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push(pair(time, tweetId));
        if (posts[userId].size() > 10) posts[userId].pop();
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        following[userId].insert(userId);
        vector<pair<int, int>> stupid;
        for (auto x: following[userId]) {
            while (posts[x].size() > 0) {
                stupid.push_back(posts[x].top());
                pq.push(posts[x].top());
                posts[x].pop();
                if (pq.size() > 10) pq.pop();
            }
            for (auto& y: stupid) posts[x].push(y);
            stupid.clear();
        }
        vector<int> temp;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            temp.insert(temp.begin(), x.second);
        }
        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
