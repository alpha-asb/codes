class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,res=0,prod=1;
        for(;r<nums.size();r++){
            prod*=nums[r];

            while(prod>=k && l<=r){
                prod/=nums[l];
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
};
