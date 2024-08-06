class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq,freq + 26,greater<int>());
        int multiple = 1,res =0;
        for(int i=0;i<26;i++){
          if(freq[i] == 0){break;}
          if(i>=8 && i%8 == 0){multiple++;}
          res += freq[i]*multiple;
        }
        return res;
    }
};
