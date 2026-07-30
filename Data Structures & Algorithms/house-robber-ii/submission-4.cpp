class Solution {
vector<int> dp1;
vector<int> dp2;
private: 
    int rec1(int i, vector<int>& arr1, vector<int>& dp1){
        if(i >= arr1.size()){
            return 0;
        }

        if(dp1[i] != -1){
            return dp1[i];
        }

        dp1[i] = max(rec1(i + 1, arr1, dp1), rec1(i + 2, arr1, dp1) + arr1[i]);
        return dp1[i];
    }
    int rec2(int i, vector<int>& arr2, vector<int>& dp2){
        if(i >= arr2.size()){
            return 0;
        }

        if(dp2[i] != -1){
            return dp2[i];
        }

        dp2[i] = max(rec2(i + 1, arr2, dp2), rec2(i + 2, arr2, dp2) + arr2[i]);

        return dp2[i];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            arr1.push_back(nums[i]);
        }

        for(int i = 1; i < n; i++){
            arr2.push_back(nums[i]);
        }
        dp1.resize(arr1.size(), -1);
        dp2.resize(arr2.size(), -1);
        return max(rec1(0, arr1, dp1), rec2(0, arr2, dp2));
    }
};
