class Solution {
public:
    void fill(vector<vector<int>>&forest,int i,int j,bool flag){
        if(!flag){
            forest[i*3][j*3] = 1;
            forest[i*3 + 1][j*3 + 1] = 1;
            forest[i*3 + 2][j*3 + 2] = 1;
        }
        else{
            forest[i*3 + 2][j*3] = 1;
            forest[i*3 + 1][j*3 + 1] = 1;
            forest[i*3][j*3 + 2] = 1;
        }
    }
    void dfs(int i,int j,int n,vector<vector<int>>&forest){
       if(i<0 || i>=n || j<0 || j>= n || forest[i][j] == 1){return;}
       forest[i][j] = 1;
       dfs(i+1,j,n,forest);
       dfs(i-1,j,n,forest);
       dfs(i,j+1,n,forest);
       dfs(i,j-1,n,forest);
       return ;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>forest(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/'){
                    fill(forest,i,j,true);
                }
                else if(grid[i][j] == '\\'){
                    fill(forest,i,j,false);
                }
            }
        }
        //cout<<n;
        int slices = 0;
        for(int i=0;i<n*3;i++){
            for(int j =0;j<n*3;j++){
                //cout<<forest[i][j]<<" ";
               if(forest[i][j] == 0){
                  slices++;
                  dfs(i,j,n*3,forest);
               }
            }
            //cout<<endl;
        }
        return slices;
    }
};
