class Solution {
public:
    
   
    string longestPalindrome(string s) {
        int ans=0;
        int startIndex;
        for(int i =0;i<s.size();i++){
            int left =i;
            int right =i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
               if(right-left+1>ans){
                ans = right-left+1;
                startIndex = left;
                }
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1>ans){
                ans = right-left+1;
                startIndex = left;
                }
                left--;
                right++;
            }

        }
        return s.substr(startIndex,ans);
    }
};
