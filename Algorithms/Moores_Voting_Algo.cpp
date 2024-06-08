class Solution {
public:
    int majorityElement(vector<int>& nums) {
     /*
      int n=nums.size();
      sort(nums.begin(),nums.end());
      int count=0;
      int i=1;
      while(count<n/2){
          if(nums[i]==nums[i-1]){
              count++;
          }
          else{count=0;}
          i++;
      }
      return nums[i-1];
      */
      
      // Approach 2 : Moores Voting Algorithm
      int cnt =0;
      int val =0;
      for(int num:nums){
        if(cnt==0){
            val = num;
        }
        if(val == num){
            cnt++;
        }
        else{
            cnt--;
        }
      }
      return val;
    }
};
