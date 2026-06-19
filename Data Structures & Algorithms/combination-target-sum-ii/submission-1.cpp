class Solution {

public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        combinations(candidates, 0, target, cur);
        return res;
        
    }
private:
    void combinations(vector<int>& candidates, int ind, int target, vector<int>& cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target < 0 || ind >= candidates.size()){
            return;
        }

        cur.push_back(candidates[ind]);
        combinations(candidates, ind + 1, target - candidates[ind], cur);
        cur.pop_back();
        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) {
            ind++;
        }
        combinations(candidates, ind + 1, target, cur);
    }
};
