class Solution {
public:
    void solve(int n,vector<string>&res,int open ,int close,string temp){
        if(open == n && close ==n){
            res.push_back(temp);
            return;
        }
        if(open<n){
            solve(n,res,open+1,close,temp+"(");
        }
        if(close<open){
            solve(n,res,open,close+1,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp ="";
        solve(n,res,0,0,temp);
        return res;
    }
};
