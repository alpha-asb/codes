class Solution {
public:
    int solve(int i,string s,unordered_set<string>&mp){
        if(i == s.size())return 0;
        int count = 0;
        for(int end = i+1;end<=s.size();end++){
            string temp = s.substr(i,end-i);
            if(mp.find(temp) == mp.end()){
                mp.insert(temp);
                count = max(count,1+solve(end,s,mp));
                mp.erase(temp);
            }
        }
        return count;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>mp;
        return solve(0,s,mp);
    }
};
