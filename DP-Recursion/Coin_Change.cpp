class Solution {

  public:
    vector<vector<int>>dp;
    int solve(vector<int> &coins, int sum,int i){
        if(sum == 0){
            return 0;
        }
        else if(i == coins.size() || sum <0){
            return INT_MAX;
        }
        if(dp[sum][i] != -1){
            return dp[sum][i];
        }
        int include = INT_MAX;
        if(sum - coins[i] >= 0){
            include = solve(coins,sum-coins[i],i);
            if(include != INT_MAX){        // important step : checking bound
                include = 1+include;
            }
        }
        int exclude = solve(coins,sum,i+1);
        return dp[sum][i] = min(include,exclude);
    }
    int minCoins(vector<int> &coins, int sum) {
        dp.resize(sum+1,vector<int>(coins.size()+1,-1));
        int res = solve(coins,sum,0);
        return (res == INT_MAX)?-1:res;
    }
};
