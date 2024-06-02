class Solution {
public:
    int solve(string word, char ch){
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                return i;
            }
        }
        return 0;
    }
    string reversePrefix(string word, char ch) {
        int reverse = solve(word,ch);
        int r=reverse;
        for(int i=0;i<=reverse/2;i++){
           swap(word[i],word[r]);
           r--;
        }
        return word;
    }
};
