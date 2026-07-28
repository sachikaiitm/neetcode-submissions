class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> sub;
        for(auto str : strs){
            vector<int> hash(26, 0);
            for(char l : str){
                hash[l - 'a']++;
            }
            sub[hash].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &it : sub){
            res.push_back(it.second);
        }

        return res;
    }
};
