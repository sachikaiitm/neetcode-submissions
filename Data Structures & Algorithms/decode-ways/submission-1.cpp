#include <cstring>
class Solution {
int dp[100];
private: 
    int rec(int ind, string& s){
        int ways = 0;
        if(ind >= s.size()){
            return 1;
        }
        if(s[ind] == '0'){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        ways += rec(ind + 1, s);

        if(ind + 1 < s.size() && stoi(s.substr(ind, 2)) <= 26 && stoi(s.substr(ind, 2)) >= 1){
            ways += rec(ind + 2, s);
        }
        return dp[ind] = ways;
    }
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};
