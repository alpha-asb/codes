class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<string>res;
       int temp1[26]={0};
       for(int i=0;i<words[0].size();i++){
        temp1[words[0][i]-'a']++;
       }
       for(auto word:words){
        int temp2[26]={0};
        for(auto c:word){
            temp2[c-'a']++;
        }
        for(int i = 0;i<26;i++){
            temp1[i] = min(temp1[i],temp2[i]);
        }
       }
       for(int i=0;i<26;i++){
         for(int j=0;j<temp1[i];j++){
            res.push_back(string(1, i + 'a'));
         }
       }
       return res;
    }
};
