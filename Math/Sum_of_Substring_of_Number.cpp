//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1000000007;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int i=0;
        vector<int>res;
        long long t_sum=0;
        while(s[i]=='0'){
            i++;
        }
        while(i<s.size()){
            res.push_back(s[i]-'0');
            i++;
        }
        long long temp=0;
        for(int j=0;j<res.size();j++){
            // t_sum+= t_sum*10+res[j] + i*res[j];
            temp = ((temp*10)%mod + res[j]%mod+ (j*res[j])%mod)%mod;
            res[j] = temp;
            t_sum= (t_sum+res[j])%mod;
        }
        
        return t_sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
