class Solution {
  public:
    int solve(string pattern, string str,int i,int j, vector<vector<int>>&dp){
        // base cases
        if(i == pattern.size() && j == str.size())return 1;
        if(i == pattern.size())return 0;
        if(j == str.size() && pattern[i] == '*')return solve(pattern,str,i+1,j,dp);
        if(j == str.size())return 0;
        if(pattern[i] != '*' && pattern[i] != '?' && pattern[i] != str[j])return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int a =0,b=0,c=0;
        if(pattern[i] == '*'){
            a = solve(pattern,str,i+1,j,dp); // consider * = empty
            b = solve(pattern,str,i,j+1,dp); // match * with multiple charecter
        }
        c = solve(pattern,str,i+1,j+1,dp); // match , this also cover ?
        return dp[i][j] = a|b|c;
    }
    int wildCard(string pattern, string str) {
        vector<vector<int>>dp(pattern.size(),vector<int>(str.size(),-1));
        return solve(pattern,str,0,0,dp);
    }
};
