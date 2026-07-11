class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
private:
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>  q;
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
        q.push({r, c});
        int anss = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];
                if (nrow >= 0 && ncol >= 0 && nrow < n &&
                    ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    anss++;
                }

            }
        }
        return anss;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans, bfs(i, j, grid, vis));
                }
            }
        }
        return ans;
    }
};
