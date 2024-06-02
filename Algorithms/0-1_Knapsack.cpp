class Solution
{
    public:
    int knap(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
         
         if(W==0 || n==0){return 0;}
         if(dp[W][n]!=-1){return dp[W][n];}
      
           if(wt[n-1]<=W){
               return dp[W][n]= max(
                   knap(W,wt,val,n-1,dp),
                   val[n-1]+knap(W-wt[n-1],wt,val,n-1,dp)
                   );
           }
           else{
              return dp[W][n]= knap(W,wt,val,n-1,dp);
           }
       
       return 1;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return knap(W,wt,val,n,dp);
      
    }
};
