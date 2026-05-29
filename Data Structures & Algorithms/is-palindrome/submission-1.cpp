class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> let;

        for (char c : s) {
            if (isalnum(c)) {
                let.push_back(tolower(c));
            }
        }
        int n = let.size();

        int l = 0;
        int r = n - 1;
        
        while(l < r){
            if(let[l] == let[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }

        return true;

    }
};
