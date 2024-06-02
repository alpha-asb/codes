
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(m,vector<int>(n,0));

	    for(int i=m-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	            if(i== m-1 && j==n-1){
	                dp[i][j]=min(0,points[i][j]);
	            }
	            else if(i==m-1){  // last row
	                dp[i][j]=min(0,dp[i][j+1] + points[i][j]);
	            }
	            else if(j==n-1){  // last column
	                dp[i][j]=min(0,dp[i+1][j] + points[i][j]);
	            }
	            else{
	            dp[i][j]=min(0,points[i][j]+max(dp[i+1][j],dp[i][j+1]));
	            }
	        }
	    }
	    return abs(dp[0][0]) +1;
	} 
};

