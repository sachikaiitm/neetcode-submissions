class Solution {
int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

private: 
    void safe(int row, int col, vector<vector<char>>& board){
        board[row][col] = 'S';

        for(int i = 0; i < 4; i++){
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];

            if(nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && board[nrow][ncol] == 'O'){
                safe(nrow, ncol, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++){
            if(board[r][0] == 'O'){
                safe(r, 0, board);
            }
            if(board[r][cols - 1] == 'O'){
                safe(r, cols - 1, board);
            }
        }
        for(int c = 0; c < cols; c++){
            if(board[0][c] == 'O'){
                safe(0, c, board);
            }
            if(board[rows - 1][c] == 'O'){
                safe(rows - 1, c, board);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
