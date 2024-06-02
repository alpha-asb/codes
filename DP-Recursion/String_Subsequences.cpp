class Solution {
  public:
/*
    Approach 1: recurssion memorization , this approach is still give TLE since eexponential increase 
    in recursive calls, memorization only help to some extent nut not more
    
    
    int solve(string s1, string s2,int m,int n,int i,int j,vector<vector<int>>&memo){
        // base case
        if(i==m){
            return (j==n)?1:0;
        }
        if(j==n){return 1;}
        
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        
        if(s1[i]==s2[j]){
            // two option : skip / not skip
            return solve(s1,s2,m,n,i+1,j,memo) + solve(s1,s2,m,n,i+1,j+1,memo);
        }
        else{
            return solve(s1,s2,m,n,i+1,j,memo);
        }
    }
    
*/
    int countWays(string s1, string s2) {
        // code 
       /* int m = s1.length(),n = s2.length();
        vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,m,n,0,0,memo);*/
        
        // Approach 2: top  down DP
        int mod  = 1e9+7;
        int m = s1.length(),n = s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++){
            dp[i][0] =1;
        }
        
        for(int i=1;i<=m;i++){
            for(int j =1;j<=n;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
