class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int res = 0;
        for(int n:arr){
            int a = n+k;
            int b = n-k;
            if(mp.find(a)!=mp.end()){
                res+=mp[a];
            }
            if(mp.find(b)!=mp.end()){
                res+=mp[b];
            }
            mp[n]++;
        }
        return res;
    }
};
