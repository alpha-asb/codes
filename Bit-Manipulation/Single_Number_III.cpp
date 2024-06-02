class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       
       //Approach 1: using map O(n) time O(n) space
       
       /*unordered_map<int,int>mp;
       vector<int>res;
       for(auto num:nums){
        mp[num]++;
       } 
       for(auto it:mp){
        if(it.second == 1){
            res.push_back(it.first);
        }
       }
       return res;*/

       // Approach 2 : Bitmanupulation

       long long xy = 0;

       for(auto x:nums){
        xy^=x;
       }
       // get the last set bit of xy;
       xy &= -xy;
       vector<int>res = {0,0};
       for(auto n:nums){
        if(xy&n){
            res[0]^=n;
            }
        else{
            res[1]^=n;
        }
       }
       return res;
    }
};
