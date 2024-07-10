class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // when row or col are only one
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans =0;
        for(int i=0;i<n;i++){
            dp[i][0] = mat[i][0];
            ans = max(ans,mat[i][0]);
        }
        for(int j=0;j<m;j++){
            dp[0][j] = mat[0][j];
            ans = max(ans,mat[0][j]);
        }
        for(int i= 1;i<n;i++){
            for(int j =1;j<m;j++){
                if(mat[i][j]==1){
                    int mini = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    dp[i][j] = mini + 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
