class Solution {
vector<int> dp;
private:
    int rec(vector<int>& nums, int index){
        //pruning
        if(index >= nums.size()){
            return 0;
        }
        //basecase
        if(dp[index] != -1) return dp[index];

        //compute
        dp[index] = max(rec(nums, index + 2) + nums[index], rec(nums, index + 1));

        //save and return
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return rec(nums, 0);
    }
};
