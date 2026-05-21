class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i = 0; i < strs.size(); i++){
            s = s + strs[i] + '.';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        string str;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '.'){
                str = str + s[i];
            }
            else{
                decoded_strs.push_back(str);
                str.clear();
            }
        }
        return decoded_strs;
    }
};
