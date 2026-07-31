#include <cstring>
class Solution {
int dp[100][100];
private: 
    int rec(int row, int col, int m, int n){
        if(row == m - 1 && col == n - 1){
            return 1;
        }
        if(row >= m || col >= n){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int ways = 0;

        if(row < m){
            ways += rec(row +1 , col, m, n);
        }
        if(col < n){
            ways += rec(row, col + 1, m, n);
        }

        return dp[row][col] = ways;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, m , n);
    }
};
