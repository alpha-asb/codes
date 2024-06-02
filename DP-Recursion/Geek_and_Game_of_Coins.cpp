class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<int>dp(n+1,0);
        dp[0]=0; // loosing
        dp[1]=1; // wining position
        for(int i =2;i<=n;i++){
            if(i-1 && !dp[i-1]){
                dp[i] =1;   
            }
            else if(i-x >=0 && !dp[i-x]){ // if the i-x is loosing then we can turn the i position winnig as both playing optimally
                dp[i] =1;
            }
            else if(i-y >=0 && !dp[i-y]){
                dp[i] =1;
            }
            else{
                dp[i] = 0;
            }
        }
        // for(int x:dp){
        //     cout<<x<<" ";
        // }
        //cout<<endl;
        return dp[n];
    }
};
