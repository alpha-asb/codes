class Solution {
public:
    long long minimumSteps(string s) {
        long long res =0,cnt = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '0'){
                cnt++;
            }
            else{
                res += cnt;
            }
        }
        return res;
    }
};
