class Solution {
public:
    // Optimal Approach : Negating the index
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            int temp = abs(nums[i]);
            nums[temp-1] = -1*abs(nums[temp-1]);
        }
        vector<int>res;
        for(int i = 0;i<n;i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
