class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum =0;
        long long temp = 0;
        long long ans = 0;
        for(long long int i=0;i<n;i++){
            temp += i*a[i];
            sum+=a[i];
        }
        ans = temp;
        for(long long int i=1;i<n;i++){
            temp = temp - sum + (long long)a[i-1]*n;
            ans = max(ans,temp);
        }
        return ans;
    }
};
