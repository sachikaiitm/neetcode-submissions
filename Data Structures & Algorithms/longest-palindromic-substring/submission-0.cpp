class Solution {
private:
    bool isPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        string str;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s) && (j - i + 1) > ans){
                    ans = j - i + 1;
                    str = s.substr(i, j - i + 1);
                }
            }
        }
        return str;
    }
};
