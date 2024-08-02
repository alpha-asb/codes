class Solution {
  public:
    
    int solve(string str1, string str2,int n,int m,vector<vector<int>>&dp){
        //base case 
        if(n==0){return m;}
        if(m==0){return n;}
        if(dp[n-1][m-1] != -1){return dp[n-1][m-1];}
        if(str1[n-1] == str2[m-1]){
            return solve(str1,str2,n-1,m-1,dp);
        }
        else{
            return dp[n-1][m-1] = 1 + min(solve(str1,str2,n-1,m-1,dp),
        min(solve(str1,str2,n-1,m,dp),solve(str1,str2,n,m-1,dp))
        );
        }
    }
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(str1,str2,n,m,dp);
    }
};
