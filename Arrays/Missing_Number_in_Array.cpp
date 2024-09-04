class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        /*
        vector<int>a(n,-1);
        for(int i=0;i<n-1;i++){
            a[arr[i]-1] = 1;
        }
        for(int i=0;i<n;i++){
            if(a[i] == -1){
                return i+1;
            }
        }
        return n;
        */
        int sum = n*(n+1)/2;
        for(int num:arr){
            sum -= num;
        }
        return sum;
    }
};
