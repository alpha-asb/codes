//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int solve(int arr[],int start,int end, vector<vector<int>>&dp){
        if(start>end){return 0;}
        if(start==end){return arr[start];}
        if(dp[start][end]!=-1){return dp[start][end];}
        
        // taking min, because we want that the opponent should get the min and our sum should me maximize
        // two choices :- if we choose left {opponent can choose left/right},hence to jumps (i+1,j-1)-->opponent choose 
        // right and (i+2,j)-->opponent choose left
        //                same for if we choose right ,two choise for opponet ,and our choices accordingly
        
        int choose_left = arr[start] + min(solve(arr,start+2,end,dp),solve(arr,start+1,end-1,dp));
        int choose_right = arr[end] + min(solve(arr,start+1,end-1,dp),solve(arr,start,end-2,dp));
        
        return dp[start][end]=max(choose_left,choose_right);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
