class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int no = 1;
        int nrow[4] = {1, 0, -1, 0};
        int ncol[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int row = r + nrow[i];
            int col = c + ncol[i];
            if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 &&!vis[row][col]){
                no += dfs(row, col, grid, vis);
            }
        }
        return no;
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
                    ans = max(ans, dfs(i, j, grid, vis));
                }
            }
        }
        return ans;
    }
};
