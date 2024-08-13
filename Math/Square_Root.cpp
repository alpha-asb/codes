class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int hi = n,lo = 1,ans = -1;
        while(lo<=hi){
            long long int mid = lo + (hi-lo)/2;
            long long int root = mid*mid;
            if(root == n){return mid;}
            else if(root < n){lo = mid+1;ans = mid;}
            else {hi = mid-1;}
        }
        return ans;
    }
};
