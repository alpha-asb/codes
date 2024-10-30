class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(nums.size(),1);
        for(int i =1;i<nums.size();i++){ // this will give longest increasing sequence 
           for(int j =0;j<i;j++){        //till curr idx
               if(nums[i]>nums[j]){
                v[i] = max(v[i],v[j]+1);
               }
           }
        }
        vector<int>v2(n,1);
        int LDS = 1;
        for(int j = n-2;j>=0;j--){
            for(int k=n-1;k>j;k--){
                if(nums[j]>nums[k]){
                    v2[j] = max(v2[j],v2[k]+1);
                    LDS = max(LDS,v2[j]);
                }
            }
        }
        int len = 0;
        for(int j=0;j<n;j++){
            if(v[j] == 1 || v2[j] == 1){
                continue;
            }
            len = max(len,v[j]+v2[j] -1);
        }
        // for(auto n:v){
        //     cout<<n<<" ";
        // }
        // cout<<endl;
        // for(auto n:v2){
        //     cout<<n<<" ";
        // }
        return  n-len;
    }
};
