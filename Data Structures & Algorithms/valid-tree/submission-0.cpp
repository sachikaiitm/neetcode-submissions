class Solution {

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push({0, -1});
        vis.insert(0);

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nei : adj[node]){
                if(nei == parent){
                    continue;
                }
                if (vis.count(nei)) {
                    return false;
                }
                vis.insert(nei);
                q.push({nei, node});
            }
        }
        return vis.size() == n; 
    }
};
