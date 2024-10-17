class Solution {
public:
    int maximumSwap(int num) {
       string s = to_string(num);
       unordered_map<int,int>mp;
       for(int i=0;i<s.size();i++){
        mp[s[i]-'0'] = i;
       }
       for(int i=0;i<s.size();i++){
        int temp = 9;
        while(temp > s[i]-'0'){
            if(mp[temp] > i){
                swap(s[i],s[mp[temp]]);
                return stoi(s);
            }
            temp--;
        }
       }
       return num;
    }
};
