class Solution{

  private:
    int solve(int arr[], int n,int idx,int currentsum,int sum,vector<vector<int>>&dp){
        // base case
        if(idx == n){
            return abs(currentsum - (sum -currentsum));
        }
        if(dp[idx][currentsum] != -1){
            return dp[idx][currentsum];
        }
        int include = solve(arr,n,idx+1,currentsum + arr[idx],sum,dp);
        int exclude = solve(arr,n,idx+1,currentsum,sum,dp);
        return dp[idx][currentsum] = min(include,exclude);
    }
  public:
	int minDifference(int arr[], int n)  { 
	    int sum =0;
	    for(int i=0;i<n;i++){
	        sum+= arr[i];
	    }
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int res = solve(arr,n,0,0,sum,dp);
        return res;
	} 
};
