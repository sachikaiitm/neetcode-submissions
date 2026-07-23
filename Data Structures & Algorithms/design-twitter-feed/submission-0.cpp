class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int, int>> tweets;   // {userId, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        for (int i = tweets.size() - 1; i >= 0 && feed.size() < 10; i--) {
            int author = tweets[i].first;
            int tweetId = tweets[i].second;

            if (author == userId ||
                following[userId].count(author)) {
                feed.push_back(tweetId);
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};