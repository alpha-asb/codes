
/*
Given an array arr[] and two integers say, x and y, find the number of sub-arrays in 
which the number of occurrences of x is equal to the number of occurrences of y.
*/
class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int diff = 0,res = 0;
        for(int num:arr){
            if(num == x){
                diff++;
            }
            else if(num == y){
                diff--;
            }
            res += mp[diff];
            mp[diff]++;
        }
        return res;
    }
};
