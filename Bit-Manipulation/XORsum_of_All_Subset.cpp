class Solution {
public:
    int solve(vector<int>& nums,int xorsum,int index){
        //base case
        if(index == nums.size()){return xorsum;}

        int includesum = solve(nums,xorsum^nums[index],index+1);

        int excludesum = solve(nums,xorsum,index+1);

        return includesum + excludesum;
    }
    int subsetXORSum(vector<int>& nums) {
      return solve(nums,0,0);
    }
};
