class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int tempMax = maxProd;

            maxProd = max({nums[i],
                           maxProd * nums[i],
                           minProd * nums[i]});

            minProd = min({nums[i],
                           tempMax * nums[i],
                           minProd * nums[i]});

            ans = max(ans, maxProd);
        }

        return ans;
    }
};