class Solution {
public:
    bool check(vector<int>freq1,vector<int>freq2){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2){
            return false;
        }
        vector<int>freq1(26,0),freq2(26,0);
        for(char c:s1){
            freq1[c-'a']++;
        }
        for(int i=0;i<n1;i++){
            freq2[s2[i]-'a']++;
        }
        if(check(freq1,freq2)){
                return true;
            }
        int j = 0;
        for(int i =n1;i<n2;i++){
            freq2[s2[j]-'a']--;
            freq2[s2[i]-'a']++;
            if(check(freq1,freq2)){
                return true;
            }
            j++;
        }
        return false;
    }
};
