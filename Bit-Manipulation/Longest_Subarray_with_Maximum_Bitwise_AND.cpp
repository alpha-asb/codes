class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0,res =0,streak =0;
        for(int num:nums){
            if(mx < num){
                mx = num;
                streak = 0;
                res =0;
            }
            if(mx == num){
                streak++;
            }
            else{
                streak = 0;
            }
            res = max(res,streak);
        }
        return res;
    }
};
