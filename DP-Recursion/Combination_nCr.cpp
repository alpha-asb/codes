class Solution{
public:
int mod = 1e9+7;
vector<vector<int>>dp;
int solve(int n,int r){
    if(r>n)return 0;
    if(n == r || r==0){return 1;}
    if(dp[n][r] != -1){return dp[n][r];}
    return dp[n][r] = (solve(n-1,r-1)%mod + solve(n-1,r)%mod)%mod;
}
    int nCr(int n, int r){
        dp.resize(n+1,vector<int>(r+1,-1));
        return solve(n,r);
    }
};
