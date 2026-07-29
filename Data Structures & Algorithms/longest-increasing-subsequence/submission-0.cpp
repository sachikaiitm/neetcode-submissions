class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        // dp[i] = Length of the Longest Increasing Subsequence
        // ending exactly at index i.
        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 1; i < n; i++) {

            // Try every previous index as a predecessor
            for (int j = 0; j < i; j++) {

                // Can nums[i] extend the subsequence ending at j?
                if (nums[j] < nums[i]) {

                    // Take the better subsequence
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};