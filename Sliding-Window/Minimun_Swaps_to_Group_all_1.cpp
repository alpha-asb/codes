class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        for(int num:nums){
            if(num == 1)cnt++;
        }
        int max_ones = 0;
        int i=0;
        int j=0;
        int curr_ones = 0;
        while(j<cnt){
            if(nums[j] == 1){
              curr_ones++;
            }
            j++;
        }
        max_ones = max(max_ones,curr_ones);

        while(j<nums.size()){
            if(nums[j] == 1)curr_ones++;
            if(nums[i] == 1)curr_ones--;

            max_ones = max(max_ones,curr_ones);
            j++;
            i++;
        }
        for(int k = 0;k<cnt;k++){
            j = j%nums.size();
            i = i%nums.size();
            if(nums[j] == 1)curr_ones++;
            if(nums[i] == 1)curr_ones--;

            max_ones = max(max_ones,curr_ones);
            j++;
            i++;
        }
        return cnt - max_ones;
    }
};
