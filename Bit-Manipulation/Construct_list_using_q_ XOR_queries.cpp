class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int>res;
        int x = 0;
        for(int i=q-1;i>=0;i--){
            if(queries[i][0] == 0){
                res.push_back(x^queries[i][1]);
            }
            else{
                x^=queries[i][1];
            }
        }
        res.push_back(0^x);
        sort(res.begin(),res.end());
        return res;
    }
};
