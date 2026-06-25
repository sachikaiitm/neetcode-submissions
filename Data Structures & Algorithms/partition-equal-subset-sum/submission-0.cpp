class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        if(totalSum % 2)
            return false;

        int sum = totalSum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        return subsetSum(nums, sum, n, dp);
    }

private:

    bool subsetSum(vector<int>& nums, int sum, int n,
                   vector<vector<int>>& dp){

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= sum; j++){

                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
};