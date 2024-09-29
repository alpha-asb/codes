class Solution
{
    public:
    vector<int>dp;
    int solve(int arr[], int n){
        if(n <= 0){
            return 0;
        }
        else if(n == 1){
            return arr[0];
        }
        else if(n == 2){
            return max(arr[0],arr[1]);
        }
        if(dp[n] != -1){return dp[n];}
        int skip = solve(arr,n-1);
        int pick = arr[n-1] + solve(arr,n-2); 
        return dp[n] = max(skip,pick);
    }
    int FindMaxSum(int arr[], int n)
    {   
        dp.resize(n+1,-1);
        return solve(arr,n);

    }
};
