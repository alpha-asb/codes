class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        long long sum = (n*(n-1))/2;
        long long arr_sum =0;
        for(int i=0;i<n-1;i++){
            arr_sum += array[i];
        }
        //cout<<sum<<" "<<arr_sum<<endl;
        return n -abs(sum-arr_sum);
    }
};
