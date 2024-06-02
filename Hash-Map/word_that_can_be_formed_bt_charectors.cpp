class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>alphabets(26,0);
        int res = 0;
        for(auto i:chars){
            alphabets[i-'a']++;
        }
        for(int i=0;i<words.size();i++){
            vector<int>temp(26,0);
            for(auto c:words[i]){
                temp[c-'a']++;
            }
            bool flag = true;
            for(int j = 0;j<26;j++){
                if(temp[j]>alphabets[j]){
                    flag =false;
                    break;
                }
            }
            if(flag){
                res+=words[i].size();
            }
        }
        return res;
    }
};
