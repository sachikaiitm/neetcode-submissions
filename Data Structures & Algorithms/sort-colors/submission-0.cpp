class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        multiset<int> ms;
        for(int i = 0; i < n; i++){
            ms.insert(nums[i]);
        }

        for(int i = 0; i < n; i++){
            auto it1 = ms.begin();
            auto it2 = next(it1, i);
            nums[i] = *it2;
        }
    }
};