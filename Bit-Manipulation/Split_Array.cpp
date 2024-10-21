/*
Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two non-empty subsets such that the XOR of elements of each group is equal. Each element should belong to exactly one subset.
Note:

The answer could be very large so print it by doing modulo with 109 + 7. 
Subsets with the same elements but derived from different indices are different.
*/



class Solution {
  public:
    int mod =1e9+7;
    int countgroup(vector<int>& arr) {
        int x =0;
        for(auto num:arr){
            x^=num;
        }
        if(x != 0){
            return 0;
        }
        // ans = 2^(n-1) - 1
        int ans = 1;
        for(int i=0;i<arr.size()-1;i++){
            ans = (ans*2)%mod;
        }
        return ans-1;
    }
};
