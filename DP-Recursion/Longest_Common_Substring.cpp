class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
         int m = str2.size();
         int len = 0;
         vector<vector<int>>dp(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
             if(str1[i] == str2[0]){
                 dp[i][0] = 1;
                 len = 1;
             }
         }
         for(int i =0;i<m;i++){
             if(str1[0] == str2[i]){
                 dp[0][i] = 1;
                 len = 1;
             }
         }
         
         for(int row = 1;row<n;row++){
             for(int col = 1;col<m;col++){
                 if(str1[row] == str2[col]){
                     dp[row][col] = dp[row-1][col-1] + 1;
                     len = max(len,dp[row][col]);
                 }
             }
         }
         return len;
    }
};
