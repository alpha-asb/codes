class Solution {
  public:
    long long int floorSqrt(long long int n) {
        int hi = n;
        int lo = 1;
        int ans = 0;
        while(lo<hi){
            long long int mid = lo + (hi-lo)/2;
            long long int root = mid*mid;
            if(root == n)return root;
            else if(root < n){lo = mid+1;ans = lo;}
            else {hi = mid-1;}
        }
        return ans;
    }
};
