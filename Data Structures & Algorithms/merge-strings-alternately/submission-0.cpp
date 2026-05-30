class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();
        int n = min(n1, n2);
        int i = 0;
        int j = 0;
        for(int x = 0; x < 2 * n; x++){
            if(x % 2 == 1){
                ans += word2[j];
                j++;
            }
            else{
                ans += word1[i];
                i++;
            }
        }

        if(n1 < n2){
            for(int k = n; k < n2; k++){
                ans += word2[k];
            }
        }
        else{
            for(int k = n; k < n1; k++){
                ans += word1[k];
            }
        }

        return ans;

    }
};