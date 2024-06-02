class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
       int target1 = arr[i] +x;
       int target2 = arr[i] -x;
       if(mp.find(target1)!=mp.end() || mp.find(target2)!=mp.end()){
           return 1;
          }
        mp[arr[i]]++;
       }
       return -1;
    }
};
