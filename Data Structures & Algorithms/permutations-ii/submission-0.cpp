class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int ind) {
        if (ind == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = ind; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[ind], nums[i]);
            backtrack(nums, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }
};