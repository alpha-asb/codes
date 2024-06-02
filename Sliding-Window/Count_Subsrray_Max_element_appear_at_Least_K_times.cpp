class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = INT_MIN;
        for(int num:nums){
            max_num=max(max_num,num);
        }
        int cnt=0,l=0; long long res=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==max_num){
                cnt++;
            }
            while(cnt>k || (l<=r && nums[l]!=max_num)){
                if(nums[l]==max_num){
                    cnt-=1;
                }
                l++;
            }
            if(cnt==k){
                    res+=l+1;
                }
        }
        return res;
    }
};
