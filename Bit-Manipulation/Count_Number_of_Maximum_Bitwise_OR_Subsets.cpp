class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto it:nums){
            maxi |= it;
        }
        int res =0;
        int n = nums.size();
        int total_subset = 1<<n;
        for(int mask = 0;mask<total_subset;mask++){
           int subsetOR = 0;
           for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                subsetOR |= nums[i];
            }
           }
           if(subsetOR == maxi){
            res++;
           }
        }
        return res;
    }
};
