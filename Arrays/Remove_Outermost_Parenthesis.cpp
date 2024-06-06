class Solution {
public:
    string removeOuterParentheses(string s) {
        // Approach 1
        /*
                string res="";
        int count = 0;
        int start =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
            count++;
            }
            else if(s[i]==')'){
                count--;
            }
            if(count ==0){
                res = res + s.substr(start+1,i-start-1);
                start = i+1;
            }
        }
        return res;

        */
        // Approach 2
       string res ="";
       int open =0;
       for(char c:s){
        if(c == '(' && open++ > 0){res+=c;}
        if(c == ')' && open-->1){res+=c;}
       } 
       return res;
    }
};
