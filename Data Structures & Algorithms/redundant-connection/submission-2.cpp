class Solution {
private:
    bool detect(int src, int dest, vector<vector<int>>& adj, vector<int>& visited) {
        if (src == dest) {
            return true;
        }

        visited[src] = 1;

        for (int nei : adj[src]) {
            if (!visited[nei]) {
                if (detect(nei, dest, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> visited(n + 1, 0);

            // If u can already reach v, adding this edge creates a cycle
            if (detect(u, v, adj, visited)) {
                return {u, v};
            }

            // Otherwise, add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};