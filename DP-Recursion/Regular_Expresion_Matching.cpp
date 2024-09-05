class Solution {
public:
    bool solve(int i,int j,string s, string p,vector<vector<int>>&memo){
        // base case
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(i>=s.size() and j>= p.size()){
            return true;
        }
        if(j >= p.size()){
            return false;
        }
        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');
        // handling *
        if(j+1 < p.size() and p[j+1] == '*'){
            bool skip = solve(i,j+2,s,p,memo);
            bool consider = match and solve(i+1,j,s,p,memo); // matching is required to use morethan 1 char at place of *
            return memo[i][j] = skip or consider;
        }
        if(match){
            return  memo[i][j] = solve(i+1,j+1,s,p,memo);
        }
        return memo[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>memo(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(0,0,s,p,memo);
    }
};
