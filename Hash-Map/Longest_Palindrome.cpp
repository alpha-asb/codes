class Solution {
public:
    int longestPalindrome(string s) {
        int charecter[52];
        for(auto c:s){
          if(c >= 'a' && c<= 'z'){
            charecter[c-'a']++;
          }
          else if(c>='A' && c<='Z'){
            charecter[c-'A'+26]++;
          }
        }
        int ans =0;
        int odd_max = 0;
        bool odd = false;
        for(int i=0;i<52;i++){
            if(charecter[i]%2==0){
                ans+=charecter[i];
            }
            else{
                ans+= charecter[i]-1;
                odd = true;
            }
        }
        if(odd){ans++;}
        return ans+odd_max;
    }
};
