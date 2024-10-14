class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum =0;
        int ans =0;
        for(int num:arr){
            sum+=num;
            if(mp.find(sum-tar)!=mp.end()){
                ans += mp[sum-tar];
            }
            mp[sum]++;
        }
        return ans;
    }
};
