class Solution {
public:
    int numSteps(string s) {
        int i= s.length() -1;
        int count =0;
        int carry =0;
        while(i>0){
            if(s[i]-'0' + carry == 0){
                carry = 0;
                count++;
            }
            else if(s[i]-'0' + carry == 2){
                count++;
                carry = 1;
            }
            else{
                count+=2;
                carry =1;
            }
            i--;
        }
        if(carry){count++;}
        return count;
    }
};
