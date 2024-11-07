class Solution {
public:
    vector<int>freq;
    void bits(int n){
       for(int i=0;i<32;i++){
        freq[i] += (n&1);
        n>>=1;
       }
    }
    int largestCombination(vector<int>& candidates) {
        freq.resize(32,0);
        for(int n:candidates){
            bits(n);
        }
        int ans =0;
        for(int i=0;i<32;i++){
            ans = max(ans,freq[i]);
        }
        return ans;
    }
};
