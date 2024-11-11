class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int cnt =0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
               int val = arr[i-1] - arr[i] + 1; 
               cnt += val;
               arr[i] += val;
            }
        }
        return cnt;
    }
};
