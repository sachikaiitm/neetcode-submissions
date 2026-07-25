class Solution {
int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c] = true;

        for(int i = 0; i < 4; i++){
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && heights[nr][nc] >= heights[r][c] && !ocean[nr][nc]){
                dfs(nr, nc, ocean, heights);
            }

        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROW = heights.size();
        int COL = heights[0].size();
        vector<vector<bool>> pac(ROW, vector<bool> (COL, false));
        vector<vector<bool>> atl(ROW, vector<bool> (COL, false));
        
        for(int col = 0; col < COL; col++){
            dfs(0, col, pac, heights);
            dfs(ROW - 1, col, atl, heights);
        }
        for(int row = 0; row < ROW; row++){
            dfs(row, 0, pac, heights);
            dfs(row, COL - 1, atl, heights);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(pac[i][j] == true && atl[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;

    }
};
