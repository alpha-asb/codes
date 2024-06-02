class Solution {
public:
    int count = 0;
    unordered_map<int,int>mp;
    void solve(vector<int>& nums, int k,int idx){
      if(idx == nums.size()){
        count++;
        return;
      }
      if(mp.find(nums[idx]-k)==mp.end() && mp.find(nums[idx]+k)==mp.end()){
        mp[nums[idx]]++;
        solve(nums,k,idx+1);
      
        mp[nums[idx]]--;
        if (mp[nums[idx]] == 0) {
                mp.erase(nums[idx]);
            }
      }
      solve(nums,k,idx+1);

    }
    int beautifulSubsets(vector<int>& nums, int k) {
       solve(nums,k,0);
       return count-1; 
    }
};
