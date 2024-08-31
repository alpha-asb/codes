class Solution{

	public:
	int mod =1e9+7;
	int solve(int i,int arr[], int n, int sum,vector<vector<int>>&memo){

	    if(i == n){
	        if(sum == 0){
	        return 1;
	        }
           return 0;
	    }
	    if(memo[i][sum] != -1){
	        return memo[i][sum];
	    } 
	     int choose = 0;
	     if(sum - arr[i] >= 0){
	       choose = solve(i+1,arr,n,sum -arr[i],memo);
	     }
         int skip = solve(i+1,arr,n,sum,memo);
         return memo[i][sum] = (choose + skip)%mod;

	}
	int perfectSum(int arr[], int n, int sum)
	{   
	    vector<vector<int>>memo(n+1,vector<int>(sum+1,-1));
        return solve(0,arr,n,sum,memo);
	}
	  
};
