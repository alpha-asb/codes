class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here'
        int ans = -1;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(a[i]-a[j])==1){
                    dp[j] = max(1+dp[i],dp[j]);
                    ans = max(ans,dp[j]);
                }
            }
        }
        return ans+1;
    }
};
