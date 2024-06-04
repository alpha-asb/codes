class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int carry =1;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' and carry){
                s[i] = '0';
                carry = 1;
            }
            else if(s[i]=='0' and carry){
                s[i] = '1';
                carry = 0;
            }
        }
        if(carry){
            return "1"+s;
        }
        int i =0;
        while(i<n and s[i]=='0'){
            i++;
        }
        s = s.substr(i);
        return s;
    }
};
