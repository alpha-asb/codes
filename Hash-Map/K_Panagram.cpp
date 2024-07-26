class Solution {
  public:

    bool kPangram(string str, int k) {
        int ch[26] = {0};
        for(auto c:str){
            if(c != ' ')ch[c-'a']++;
        }
        int missing = 0;
        int extra = 0;
        for(int i=0;i<26;i++){
            if(ch[i]==0){
                missing++;
            }
            else{
                extra+=(ch[i]-1);
            }
        }
        return extra>=missing && missing <=k;
    }
};
