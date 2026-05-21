class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int days_req = 1;
            int current_load = 0;

            for (int w : weights) {
                if (current_load + w <= mid) {
                    current_load += w;
                } else {
                    days_req++;
                    current_load = w;
                }
            }

            if (days_req <= days) {
                res = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return res;
    }
};