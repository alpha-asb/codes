class Solution
{
    public:
    int mod = 1e9+7;
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int m = s.length(),n = t.length();
      vector<vector<int>>dp(m+1,vector<int>(n+1,0));
      
      // id t is empty ; then exactly 1 way we can get it by choosing []
      for(int i=0;i<=m;i++){
          dp[i][0] = 1;
      }
      
      for(int i=1;i<=m;i++){
          for(int j =1;j<=n;j++){
              if(s[i-1]==t[j-1]){  // if match  : two option take + untake
                  dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
              }
              else{
                  dp[i][j] = dp[i-1][j]; // mismatch : untake
              }
          }
      }
      return dp[m][n];
    }
};
