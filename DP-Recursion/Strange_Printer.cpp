class Solution {
public:
    int solve(int start,int end,string s,vector<vector<int>>&memo){
        if(start>end){
            return 0;
        }
        if(memo[start][end] != -1){
            return memo[start][end];
        }
        int turns = 1 + solve(start+1,end,s,memo);  // worst case
        // split the sring in two part if find matching char
        for(int i = start+1;i<=end;i++){
            if(s[i] == s[start]){
                int turnwithMatch = solve(start,i-1,s,memo) + solve(i+1,end,s,memo);
                turns = min(turns,turnwithMatch);
            }
        }
        return memo[start][end] = turns;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,memo);
    }
};
