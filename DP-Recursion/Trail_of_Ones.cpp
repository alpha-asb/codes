class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        int mod = 1e9+7;
        int ans =1;
        int a =0;
        int b =1;
        if(n==2){return 1;}
        for(int i=3;i<=n;i++){
            int c = (a+b)%mod;
            a = b;
            b = c; 
            ans = ((ans*2)%mod + c)%mod;
        }
        return ans;
    }
};
