class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<int> freq(nums.size(), 0);
        per(nums, cur, freq, res);
        return res;
    }

    void per(vector<int>& nums, vector<int>& cur, vector<int>& freq, vector<vector<int>>& res){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                cur.push_back(nums[i]);
                freq[i] = 1;  
                per(nums, cur, freq, res);
                freq[i] = 0;
                cur.pop_back();
            }
        }
    }
};
