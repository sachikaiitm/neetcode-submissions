class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxVal = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            sum += piles[i];
            maxVal = max(maxVal, piles[i]);
        }
        int low = 1;
        int high = maxVal;
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            if (mid == 0) { low = 1; continue; }
            long long hours = 0;
            for(int i = 0; i < n; i++){
                hours += (piles[i] + mid - 1LL) / mid;
            }

            if(hours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return ans;
    }
};
