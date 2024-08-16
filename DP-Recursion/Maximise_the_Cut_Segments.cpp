class Solution
{
    private:
    int solve(int n, int x, int y, int z,vector<int>&dp){
        if(n == 0){return 0;}
        if(n < 0){return INT_MIN;}
        if(dp[n]!= -1){return dp[n];}
        int cut_x = solve(n-x,x,y,z,dp);
        int cut_y = solve(n-y,x,y,z,dp);
        int cut_z = solve(n-z,x,y,z,dp);
        
        int maxi = max({cut_x,cut_y,cut_z});
        return dp[n] = (maxi==INT_MIN)?INT_MIN : 1+maxi;
    }
    public:
    int max_cuts = 0;
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int cuts =0;
        int arr[] = {x,y,z};
        vector<int>dp(n+1,-1);
        int result = solve(n,x,y,z,dp);
        return max(0,result);
    }
};
