class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long ans =1;
        for(int n:arr){
            if(n > ans){
                return ans;
            }
            ans += n;
        }
        return ans;
    }
};
