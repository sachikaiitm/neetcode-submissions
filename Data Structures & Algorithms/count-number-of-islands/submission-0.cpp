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
            int row = node.first;
            int col = node.second;
            for(int i = 0; i < 4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size()&& grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == '1'){
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

};
