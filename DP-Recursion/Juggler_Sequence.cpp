class Solution {
  public:
    void solve(int n,vector<int>&res){
        res.push_back(n);
        if(n==1 || n<1){return;}
        if(n%2 == 0){
            solve(pow(n,1.0/2),res);
        }
        else{
            solve(pow(n,3.0/2),res);
        }
    }
    vector<int> jugglerSequence(int n) {
        // code here
        vector<int>res;
        solve(n,res);
        return res;
    }
};
