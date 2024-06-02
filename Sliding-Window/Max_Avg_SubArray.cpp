class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double res =INT_MIN;
        int i=0,j=0,n=nums.size();
        while(i<k){
            sum+=nums[i];
            i++;
        }
        res = max(res,sum);
        while(i<n){
            sum+=nums[i];
            sum-=nums[j];
            i++;
            j++;
            res = max(res,sum);
        }
        return res/k;
    }
};
