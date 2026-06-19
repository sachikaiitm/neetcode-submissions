class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
         vector<int> cur;
         comb(cur, 1, k, n);
         return res;
    }

    void comb(vector<int>& cur, int i, int k, int n){
        if (i > n) {
            if (cur.size() == k) {
                res.push_back(cur);
            }
            return;
        }
    

        cur.push_back(i);
        comb(cur, i + 1, k, n);
        cur.pop_back();
        comb(cur, i + 1, k, n);
    }
};