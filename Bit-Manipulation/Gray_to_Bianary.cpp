//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    
    int grayToBinary(int n)
    {
        
        // Your code here
        
        /// to convert gray code to binary : we are intializing res as 0 and taking xor with n and updating
        //   n by shifting it to right by 1 bit;
        int gray =0;
        while(n){
            gray^=n ;
            n>>=1;
        } 
        return gray;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends
