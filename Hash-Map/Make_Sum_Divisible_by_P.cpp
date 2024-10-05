class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum =0;
        for(int x:nums){
            sum += x;
        }
        if(sum%p == 0){
            return 0;
        }
        unordered_map<int,int>mp;
        mp[0] = -1;           // if dont include any element can always be found
        int target = sum%p;
        int currSum = 0;
        int n = nums.size();
        int len = n;
        for(int i=0;i<nums.size();i++){
            currSum = (currSum + nums[i])%p;
            int diff = (currSum - target + p)%p;
            if(mp.count(diff) > 0){
             len = min(len,i-mp[diff]);
            }
            mp[currSum] = i;
        }
        return (len == n)?-1:len;
    }
};
