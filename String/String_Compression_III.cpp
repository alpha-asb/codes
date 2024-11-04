class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string res = "";
        int cnt =1;
        int i=1;
        for(;i<n;i++){
            if(word[i] == word[i-1] && cnt<9){
                cnt++;
            }
            else{
                res += to_string(cnt);
                res += word[i-1];
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res += word[i-1];
        return res;
    }
};
