class Solution {
public:
    bool isValid(int i,int j, int m,int n,vector<vector<int>>& grid){
        return (i>=0 && i<m && j>=0 && j<n && grid[i][j]==1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans =0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count =0;
                if(grid[i][j]==1){
                    if(isValid(i+1,j,m,n,grid)){
                        count++;
                    }
                    if(isValid(i-1,j,m,n,grid)){
                        count++;
                    }
                    if(isValid(i,j+1,m,n,grid)){
                        count++;
                    }
                    if(isValid(i,j-1,m,n,grid)){
                        count++;
                    }
                    ans += 4 - count;
                }
            }
        }
        return ans;
    }
};
