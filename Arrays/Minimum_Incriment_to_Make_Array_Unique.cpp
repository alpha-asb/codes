class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_set<int>mp;
        sort(nums.begin(),nums.end());
        int ans =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int temp = nums[i];
                nums[i] = nums[i-1]+1;
                ans = ans + nums[i]-temp;
            }
        }
        
        return ans;
    }
};
