class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        multiset<int> sorted;
        for(int i = 0; i < n; i++){
            sorted.insert(nums[i]);
        }
        for(int i = 0; i < n; i++){
            auto it1 = sorted.begin();
            auto it2 = next(it1, i);
            nums[i] = *it2;
        }
        return nums;
    }
};