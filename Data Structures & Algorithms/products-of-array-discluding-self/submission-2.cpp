class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_mul(n, 1);
        for(int i = 1; i < n; i++){
            prefix_mul[i] *=  nums[i - 1] * prefix_mul[i - 1];
        }
        vector<int> suffix_mul(n, 1);
        for(int i = n - 2; i >= 0; i--){
            suffix_mul[i] *= nums[i + 1] * suffix_mul[i + 1];
        }

        vector<int> ans(n , 1);

        for(int i = 0; i < n; i++){
            ans[i] = prefix_mul[i] * suffix_mul[i];
        }

        return ans;
    }
};