class Solution {
  public:
    int maxIndexDiff(vector<int> arr) {
        int n = arr.size();
        vector<int>rightMax(n,1);
        rightMax[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
          rightMax[i] = max(arr[i],rightMax[i+1]);
        }
        int i =0,j=0;
        int res = 0;
        while(j<n && i<n){
            if(rightMax[j] >= arr[i]){
                res = max(res,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return res;
    }
};
