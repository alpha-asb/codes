class Solution {
public:
    // int solve(int n,vector<int>&dp){
    //     if(dp[n]!=-1){return dp[n];}
    //     if(n==0){return 0;}
    //     if(n==1 || n==2){return 1;}
    //     return dp[n] = solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp);
    // }
    int tribonacci(int n) {
    //     vector<int>dp(n+1,-1);
    //     return solve(n,dp);

    // approach 2 : O(n) time and O(1) space
    if(n < 2)
            return n;
        int a1 = 0, a2 = 1, a3 = 1, t;
        while(n > 2) {
            t = a1 + a2 + a3;
            a1 = a2;
            a2 = a3;
            a3 = t;
            n--;
        }
        return a3;

     }
};
