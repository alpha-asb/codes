class Solution {

  public:
  
    int LCS(string x,string y,vector<vector<int>>&dp){
        int m = x.size(),n = y.size();
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int m = x.size();
        int n = y.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int count = LCS(x,y,dp);
        return (m-count)*costX + (n-count)*costY;
    }
};
