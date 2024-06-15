class Solution {
  public:
    long long solve(int i,int j,int n,vector<vector<vector<long long>>>&dp){
        if(i<0 || i>=4 || j<0 || j>2){return 0;}
        if(i==3 and (j==0 or j==2)){return 0;}
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        
        if(n==1) return 1;
        return dp[i][j][n]=solve(i-1,j,n-1,dp)+solve(i+1,j,n-1,dp)+solve(i,j-1,n-1,dp)+solve(i,j+1,n-1,dp)+solve(i,j,n-1,dp);
    }
    
    long long getCount(int n) {
        // Your code goes here
        long long ans =0;
        vector<vector<vector<long long>>>dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==3 && (j==0 or j==2))continue;
                ans+= solve(i,j,n,dp);
            }
        }
        return ans;
    }
};
