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
        for (int i = 0; i < n / 2; i++) {
            if (let[i] != let[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
