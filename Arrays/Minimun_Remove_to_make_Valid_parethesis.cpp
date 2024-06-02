class Solution {
public:
 // Approah : 1) Two pass
 //           2) 
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        string res="";
        for(char x:s){
            if(x=='('){
                res+=x;
                cnt++;
            }
            else if(x==')' && cnt>0){
                res+= x;
                cnt--;
            }
            else if(x!=')'){
                res+=x;
            }
        }
        for(int i=res.size();i>=0;i--){
            if(res[i]=='(' && cnt>0){
                res[i]='*';
                cnt--;
            }
        }
        
        string result="";
        for(char c:res){
            if(c!='*'){
                result+=c;
            }
        }
        return result;
    }
};
