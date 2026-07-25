class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
private:

    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int ROW = node.first;
            int COL = node.second;
            for(int i = 0; i < 4; i++){
                int nr = ROW + directions[i][0];
                int nc = COL + directions[i][1];
                if(nc >= 0 && nc < grid[0].size() && nr >= 0 && nr < grid.size() && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int island = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};
