class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, cur);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector<int>& cur){
        if(i == nums.size()){
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur);
        cur.pop_back();
        if(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        dfs(nums, i + 1, cur);
    }

};
