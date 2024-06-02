class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;
    int solve(int n,int k ,int target){
        if(n==0){
            if(target ==0){return 1;}
            return 0;
        }
        if(target <0){return 0;}
        if(dp[n][target]!=-1){return dp[n][target];}
        int res =0;
        for(int i = k;i>0;i--){
             res = (res%mod + solve(n-1,k,target-i)%mod)%mod;
        }
        return dp[n][target] = res%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp = vector<vector<int>>(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
    }
};
