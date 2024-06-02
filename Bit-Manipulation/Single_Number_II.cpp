class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenonce =0,seentwice =0;
        for(auto num:nums){
           seenonce = (seenonce^num) & (~seentwice);
           seentwice = (seentwice^num) & (~seenonce);
        }
     return seenonce;
    }
};
