class Solution {
public:
    bool checkRecord(string s) {
       int A = 0;
       int L = 1;
       int max_L = 0;
       for(int i=0;i<s.size()-1;i++){
        if(s[i] == 'A'){A++;}
        else if(s[i]=='L' && s[i+1]=='L'){
            L++;
            max_L = max(max_L,L);
        }
        else{
            L = 1;
        }
       } 
       if(s[s.size()-1]=='A'){A++;}
       return A<2 && max_L<3;
    }
};
