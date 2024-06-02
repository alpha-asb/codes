
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
	       vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, a, b, dp);
    }
    
    int solve(int i, int j, int a[], int b[], vector<vector<int>>& dp) {
        
         if (j < 0) {
            return 0;
        }
        if (i < 0) {
            return INT_MIN;
        }
       
        
        // If result is already calculated, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Calculate the maximum dot product recursively
        int pick = a[i] * b[j] + solve(i - 1, j - 1, a, b, dp) ;
        int not_pick = solve(i - 1, j, a, b, dp);
        
        // Store the result in the dp array
        dp[i][j] = max(pick, not_pick);
        
        return dp[i][j];
	}
};


