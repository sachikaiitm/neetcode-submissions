class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int index = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                index = mid;
                high = mid - 1;
            }
        }
        if(target < nums[0]) return 0;
        else if (target > nums[n - 1]) return n;
        else return index;
    }
};