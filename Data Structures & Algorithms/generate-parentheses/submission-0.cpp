class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        vector<char> cur;
        perm(res, n, cur, 0, 0);
        return res;
    }
private:
    void perm(vector<string>& res, int n, vector<char>& cur, int open, int close){

        if(open == close && close == n){
            res.push_back(string(cur.begin(), cur.end()));
            return;
        }
        if(open < n){
            cur.push_back('(');
            perm(res, n, cur, open + 1, close);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            perm(res, n, cur, open, close + 1);
            cur.pop_back();
        }

    }
};
