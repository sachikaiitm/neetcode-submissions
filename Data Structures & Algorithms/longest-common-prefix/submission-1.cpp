class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string common = strs[0];
        int stringlen = common.size();

        int wrong = INT_MAX;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < stringlen; j++){
                if(strs[i][j] != common[j]){
                    wrong = j;
                    break;
                }
            }
            if(wrong != INT_MAX){
                common.erase(common.begin() + wrong, common.end()); 
            }
        }
        return common;

    }

};