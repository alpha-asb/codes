class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
        // O(n)^2  -->TLE
        int n = s.size();
        for(int i = 0;i<n/2;i++){
         int len = i+1;
         string temp = s.substr(0,len);
         if(n%len == 0){
           int frags = n/len;
           string check="";
           for(int j =0;j<frags;j++){
               check = check + temp;
           }
           if(check == s){
            return true;
           }
         }
        }
        return false;
        */

        //Approach 2: string doubling ->linear time

        int n = s.size();
        string doubled = s+s;
        string substring = doubled.substr(1,2*n -2);
        return substring.find(s)!=string::npos;
    }
};
