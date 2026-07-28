class Solution {
private:
    void bfs(int node, vector<vector<int>>& adj,vector<int>& visited){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nei : adj[cur]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }

    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int res = 0;
        for(int node = 0; node < n; node++){
            if(!visited[node]){
                bfs(node, adj, visited);
                res++;
            }
        }
        return res;
    }
};
