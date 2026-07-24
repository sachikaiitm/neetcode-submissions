class Twitter {
private:
    int timer;
    unordered_map<int , vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer, tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {

        followMap[userId].insert(userId);

        priority_queue<pair<int, pair<int,int>>> feed;

        for (int followee : followMap[userId]) {

            if (!tweetMap[followee].empty()) {

                int idx = tweetMap[followee].size() - 1;
                int time = tweetMap[followee][idx].first;

                feed.push({time, {followee, idx}});
            }
        }

        vector<int> ans;

        while (!feed.empty() && ans.size() < 10) {

            auto curr = feed.top();
            feed.pop();

            int followee = curr.second.first;
            int idx = curr.second.second;

            ans.push_back(tweetMap[followee][idx].second);

            if (idx > 0) {

                idx--;

                int newTime = tweetMap[followee][idx].first;

                feed.push({newTime, {followee, idx}});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
