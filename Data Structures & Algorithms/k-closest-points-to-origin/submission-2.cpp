class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            maxHeap.push({dist, {x, y}});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while (!maxHeap.empty()) {
            auto coord = maxHeap.top().second;
            ans.push_back({coord.first, coord.second});
            maxHeap.pop();
        }

        return ans;
    }
};