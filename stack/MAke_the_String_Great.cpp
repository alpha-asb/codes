class Solution {
public:
    // string solve(string s){
    //     if(s.size()<2){
    //         return s;
    //     }
    //     string res="";
    //     int i=0;
    //     for(;i<s.size()-1;i++){
    //        if(abs((s[i]-'a')-(s[i+1]-'a'))==32){
    //         i++;
    //         continue;
    //        }
    //        else{
    //         res+=s[i];
    //        }
    //     }
    //     if(i==s.size()-1 && abs((s[i]-'a')-(s[i-1]-'a'))!=32){
    //         res+=s[i];
    //     }

    //     return res;
    // }
    string makeGood(string s) {
       stack<char> st;
       for(int i=0;i<s.size();i++){
        if(!st.empty() && abs((st.top()-'a')-(s[i]-'a'))==32){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
       }
       string res="";
       while(!st.empty()){
        res+=st.top();
        st.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
