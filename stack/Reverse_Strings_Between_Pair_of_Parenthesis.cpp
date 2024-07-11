/*
Approach 1 : Brutt Force , O(N^2) Time and O(N) Space

class Solution {
public:
    void reverse(int &start,int &end,string &s){
        while(start<end){
            swap(s[start],s[end]);
            start++;end--;
        }
    }
    string reverseParentheses(string s) {
        stack<int>st;
        string temp = s;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int start = st.top()+1;
                int end = i-1;
                reverse(start,end,temp);
                st.pop();
            }
        }
        string res ="";
        for(auto c:temp){
            if(c != '(' && c != ')'){
                res+=c;
            }
        }
        return res;
    }
};
*/

// Approach 2 : Warmhole Approach , O(N) Time and O(N) Space

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>openparenthesis;
        vector<int>pair(s.size());

        // first pass : making pairs 
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                openparenthesis.push(i);
            }
            else if(s[i] == ')'){
                int j = openparenthesis.top();
                openparenthesis.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        // second pass : build result

        string res="";

        for(int curr_idx = 0,dir = 1;curr_idx < s.size();curr_idx+=dir){
            if(s[curr_idx] == '(' || s[curr_idx] == ')'){
                curr_idx = pair[curr_idx];
                dir = -dir;
            }
            else{
                res+=s[curr_idx];
            }
        }
        return res;
    }
};
