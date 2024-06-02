class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>ast;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                ast.push(i);
            }
            else{
                // s[i] == ')'
                if(!st.empty()){
                    st.pop();
                }
                else if(!ast.empty()){
                    ast.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!st.empty() && !ast.empty()){
            if(st.top()>ast.top()){
                return false;
            }
            st.pop();
            ast.pop();
        }
        return st.empty();
    }
};
