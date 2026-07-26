class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> hash_1(26, 0);

        for(char c : s1){
            hash_1[c - 'a']++;
        }
        
        for(int i = 0; i < s2.size() - s1.size() + 1; i++){
            vector<int> hash_2(26, 0);
            for(int j = i; j < i + s1.size(); j++){
                hash_2[s2[j] - 'a']++;
            }
            bool flag = true;
            for(int k = 0; k < 26; k++){
                if(hash_1[k] != hash_2[k]){
                    flag = false;
                }
            }
            if(flag){
                return true;
            }

        }
        return false;
    }
};
