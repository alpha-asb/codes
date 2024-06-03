class Solution {
public:
   /*Find the longest prefix of t that is a subsequence of s
   Use two variables to keep track of your location in s and t.
   If the characters match, increment both variables. Otherwise, only increment the variable for s.*/
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
    
        for(int k=0;k<s.size();k++){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        return t.size()-j;
    }
};
