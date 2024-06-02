class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        int i=0;
        long max_sum = 0;
        long sum = 0;
        while(i<n){
            if(arr[i]<=k){
                sum+=arr[i];
            }
            else{
                max_sum = max(max_sum,sum);
                sum=0;
            }
            i++;
        }
        max_sum = max(max_sum,sum);
        return max_sum;
    }
};
