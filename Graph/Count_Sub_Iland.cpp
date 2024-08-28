class Solution {

private:
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &isSubiland){
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j] == 0){
            return;
        }
        if(grid1[i][j] != grid2[i][j]){
            isSubiland = false;
        }
        grid1[i][j] = 0;
        grid2[i][j] = 0;
        dfs(i-1,j,n,m,grid1,grid2,isSubiland);
        dfs(i+1,j,n,m,grid1,grid2,isSubiland);
        dfs(i,j-1,n,m,grid1,grid2,isSubiland);
        dfs(i,j+1,n,m,grid1,grid2,isSubiland);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int res =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1 ){
                    bool isSubiland = true;
                    dfs(i,j,n,m,grid1,grid2,isSubiland);
                    if(isSubiland){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
