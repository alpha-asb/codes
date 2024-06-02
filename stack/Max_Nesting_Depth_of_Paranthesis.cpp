class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<char>st;
        for(auto x:s){
          if(x=='('){
              st.push('(');
              if(st.size()>ans){
                  ans= st.size();
              }
          }
          else if(x==')' && !st.empty()){
              st.pop();
          }
        }
        return ans;
    }
};
