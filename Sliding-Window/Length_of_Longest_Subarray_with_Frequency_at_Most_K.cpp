class Solution {
public:

   // sliding window and unordered_map approach
    int maxSubarrayLength(vector<int>& nums, int k) {
       int l=0,r=0,ans=0;
        unordered_map<int,int>mp;
       while(r<nums.size()){
           mp[nums[r]]++;
           if(mp[nums[r]]>k){
            while(nums[l]!=nums[r]){
                mp[nums[l]]--;
                l++;
            }
            mp[nums[l]]--;
            l++;
           }
           r++;
           ans=max(ans,r-l);
       } 
       return ans;
    }
};
