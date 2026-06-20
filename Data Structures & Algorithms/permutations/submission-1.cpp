class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, res, 0);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int ind){

        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);

            backtrack(nums, res, ind + 1);

            swap(nums[i], nums[ind]); 
        }
    }
};
