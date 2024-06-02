//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    set<vector<int>>res;
    void solve(vector<int> &arr,int sum,vector<int>&temp,int i,int n){
        if(sum<0){return;}
        if(sum==0){res.insert(temp); return;}
           
        if(i == n){
            return;
        }
        // Include current element
        temp.push_back(arr[i]);
        solve(arr, sum - arr[i], temp, i + 1,n);
        temp.pop_back(); // Backtrack
        solve(arr, sum, temp, i + 1,n);
        
    }
    
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<int>temp;
        sort(arr.begin(),arr.end());
        solve(arr,k,temp,0,n);
        vector<vector<int>>result;
        for(auto it:res){
            result.push_back(it);
        }
        return result;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
