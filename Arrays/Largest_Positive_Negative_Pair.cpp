class Solution {
public:
    int findMaxK(vector<int>& nums) {

    //    Approach 1 : O(n) time and O(n) space

        // unordered_map<int,int>mp;
        // int ans = -1;
        // for(int num:nums){
        //     if(mp.find(abs(num))!= mp.end()){
        //        if(num > 0 && mp[abs(num)] == -1){
        //           ans = max(ans,abs(num));
        //        }
        //        else if(num<0 && mp[abs(num)]==1){
        //          ans = max(ans,abs(num));
        //        }
        //     }
        //     else{
        //         mp[abs(num)] = (num > 0) ? 1 : -1;
        //     }
        // }
        // // for(auto it:mp){
        // //     cout<<it.first<<" "<<it.second<<endl;
        // // }
        // return ans;

        // Approach 2: O(nlog(n)) time and O(1) space

        sort(nums.begin(),nums.end());
        int i= 0,j=nums.size()-1;
        while(i<j && nums[i] < 0 && nums[j] > 0){ //adding condition such that nums[i]<0 and nums[j]>0 so that we get the negative and positive pair
            if(abs(nums[i]) == nums[j]){return nums[j];}
            else if(abs(nums[i])>nums[j]){i++;}
            else{j--;}
            }
        
        return -1;
    }
};
