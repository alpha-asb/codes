class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& nums,int index,vector<int>&output){
        if(index>=nums.size()){
            res.push_back(output);
            
            return;
        }
        output.push_back(nums[index]);
        solve(nums,index+1,output);
        output.pop_back();
        solve(nums,index+1,output);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>output;
        int index=0;
        solve(nums,index,output);
        return res;
    }
};
