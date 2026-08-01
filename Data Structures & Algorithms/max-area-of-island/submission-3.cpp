class Solution {
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0 , -1}};
private:
    int dfs(int r, int c, vector<vector<int>>& grid){
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++) {
            res += dfs(r + directions[i][0],
                             c + directions[i][1], grid);
        }
        return res;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        int ans = 0;

        for(int r = 0; r < ROW; r++){
            for(int c = 0; c < COL; c++){
                if(grid[r][c] == 1){
                    ans = max(ans, dfs(r, c, grid));
                }
            }
        }

        return ans;
    }
};