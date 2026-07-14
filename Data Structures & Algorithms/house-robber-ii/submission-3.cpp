class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return *max_element(nums.begin(), nums.end());
        }

        return max(helper(nums, 0, n - 2) , helper(nums, 1, n - 1));
    }

    int helper(vector<int>& nums, int l, int r) {
        int len = r - l + 1;

        vector<int> dp(len + 1, 0);
        dp[1] = nums[l];

        for (int i = 2; i <= len; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[l + i - 1]);
        }
        return dp[len];
    }
};
