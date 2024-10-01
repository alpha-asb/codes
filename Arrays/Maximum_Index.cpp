class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
    int maxIndexDiff(vector<int>& arr) {
       int n = arr.size();
       vector<int>leftmin(n,0),rightmax(n,0);
       leftmin[0] = arr[0];
       rightmax[n-1] = arr[n-1];
       for(int i=1;i<n;i++){
           leftmin[i] = min(leftmin[i-1],arr[i]);
       }
       for(int i=n-2;i>=0;i--){
           rightmax[i] = max(rightmax[i+1],arr[i]);
       }
       int i = 0,j = 0;
       int res = 0;
       while(i<n && j<n){
           if(leftmin[i] <= rightmax[j]){
               res = max(res,j-i);   // update answer
               j++;
           }
           else{
               i++;
           }
       }
       return res;
    }
};
