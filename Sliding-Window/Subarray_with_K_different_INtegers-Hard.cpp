class Solution {
public:
    // we can calculate the number of subarray with at most K distinct integer
    // also number of subarray with at most K-1 distinct integer
    // answer = solve(K)-solve(K-1)

    int solve(vector<int>& nums, int k){
        if(k==0){return 0;}
        int l=0,r=0,cnt=0,res=0;
        unordered_map<int,int>mp;
        for(;r<nums.size();r++){
           if(mp[nums[r]]==0){
            cnt++;
            mp[nums[r]]++;
           }
           else{
            mp[nums[r]]++;
           }
           while(cnt>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
                cnt--;
            }
            l++;
           }
             // At this point, the window [left, right] has at most k distinct integers.
            // So, all subarrays ending at index 'right' with at most k distinct integers are valid.
            // r-l +1 gives all the subarray ending at r
           res+=r-l+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
