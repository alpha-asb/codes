class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>grid(m,vector<int>(n,0));
        k = k%n;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               grid[i][j] = mat[i][(j+k)%n] ;
            }
        }
        return grid;
    }
};
