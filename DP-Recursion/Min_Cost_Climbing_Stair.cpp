class Solution {

public:

     int helper(vector<int>& cost,int n,vector<int>&dp){
         if(dp[n]!=-1){return dp[n];}
         if(n<=1){return dp[n]=0;}
         if(n==2){return dp[n]=min(cost[n-2],cost[n-1]);}
         return dp[n]= min(cost[n-1]+helper(cost,n-1,dp),cost[n-2]+helper(cost,n-2,dp));
     }
   
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return helper(cost,cost.size(),dp);
    }
};
