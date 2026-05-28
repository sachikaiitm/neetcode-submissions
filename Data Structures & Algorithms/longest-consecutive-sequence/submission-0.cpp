class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0){
            return 0;
        }
        int count = 1;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int current = 1;
            int indx = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] == nums[indx] + 1){
                    current++;
                    indx = j;
                }
                else if(nums[j] == nums[indx]){
                    continue;
                }
                else{
                    break;
                }
            }
            count = max(current, count);
        }
        return count;
    }
};
