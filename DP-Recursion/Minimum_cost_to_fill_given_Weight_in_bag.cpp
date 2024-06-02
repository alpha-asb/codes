class Solution {
  public:
    int solve( int w, vector<int> &cost,vector<int>&dp){
        if(w<0){return 1e9;}
        if(w == 0){return 0;}
        if(dp[w]!=-1){return dp[w];}
         int min_cost = 1e9;  // Start with a large number to find the minimum
        for (int i = 1; i <= cost.size(); i++) {
            if (cost[i - 1] != -1 && w >= i) {
                min_cost = min(min_cost, cost[i - 1] + solve(w - i, cost, dp));
            }
        }
        return dp[w] = min_cost;
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<int>dp(w+1,-1);
        int ans = solve(w,cost,dp);
        return (ans >= 1e9)?-1:ans;
    }
};
