class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxi[i] = max(nums[i], maxi[i-1]+nums[i]);
        }
        return *max_element(maxi.begin(), maxi.end());
    }
};
