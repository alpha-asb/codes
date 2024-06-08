class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      /*  Approach 1: Brutt Force O(n^2)
      for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum%k==0){
                    return true;
                }
            }
        }
        return false;
        */

        // Approach two prefix sum and hash table of reminders
        // concept : if found the same remainder of prefix sum this means 
        //           their exist a subarray sum window with remainder 0

        int n = nums.size();
        int sum = 0;
        if(n<2){return false;}
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i =0;i<n;i++){
            sum+=nums[i];
            //if(sum%k==0){return true;}
            int rem = sum%k;
            if (rem < 0) rem += k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem] >1){return true;}
            }
            else{mp[rem] = i;}
        }
    return false;
    /*
    class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int prev_sum = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = (sum + nums[i])%k;
            if(st.find(sum) != st.end())
            return true;
            st.insert(prev_sum); //to make it size 2
            prev_sum = sum;
        }
        return false;
    }
};
    */
    }
};
