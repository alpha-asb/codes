class Solution {
  public:
    int majorityElement(vector<int>& arr) {
      int val = 0;
      int cnt =0;
      for(int num:arr){
          if(cnt == 0){
              val = num;
          }
          if(val == num){
              cnt++;
          }
          else{
              cnt--;
          }
      }
      // verifying
      int cnt2 =0;
      for(int num:arr){
          if(num == val){
              cnt2++;
          }
      }
      if(cnt2 <= arr.size()/2 ){
          return -1;
      }
      return val;
    }
};
