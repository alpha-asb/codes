class Solution {
public:
    vector<int>lettercount;
    vector<int>wordlettercount;
    int ans =0;
    Solution() : lettercount(26, 0), wordlettercount(26, 0), ans(0) {}
    void solve(int idx,vector<string>& words,vector<int>& score,int &temp){
        for(int i=0;i<26;i++){
            if(wordlettercount[i]>lettercount[i]){
                return;
            }
        }
        ans = max(ans,temp);
        for(int i = idx;i<words.size();i++){
            for(auto c:words[i]){
                wordlettercount[c - 'a']++;
                temp+=score[c - 'a'];
            }
            solve(i+1,words,score,temp);
            for(auto c:words[i]){
                wordlettercount[c - 'a']--;
                temp-=score[c - 'a'];
            }
        }
        

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    for(auto &c :letters){
        lettercount[c-'a']++;
    }
    int temp =0;
    solve(0,words,score,temp);
    return ans;
    }
};
