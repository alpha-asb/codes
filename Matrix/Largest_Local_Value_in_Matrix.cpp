class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>res(n-2,vector(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int temp = 0;
                for(int m = i;m<i+3;m++){
                    for(int n= j;n<j+3;n++){
                        temp = max(temp,grid[m][n]);
                    }
                }
                res[i][j] = temp;
            }
        }
        return res;
    }
};
