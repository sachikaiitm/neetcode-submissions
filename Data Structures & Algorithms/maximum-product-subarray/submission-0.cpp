class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxP(n);
        vector<int> minP(n);

        maxP[0] = nums[0];
        minP[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            maxP[i] = max({nums[i],
                           maxP[i - 1] * nums[i],
                           minP[i - 1] * nums[i]});

            minP[i] = min({nums[i],
                           maxP[i - 1] * nums[i],
                           minP[i - 1] * nums[i]});

            ans = max(ans, maxP[i]);
        }

        return ans;
    }
};