class Solution {
public:
    void fliprow(vector<vector<int>>& grid,int i,int n){
        for(int j=0;j<n;j++){
            grid[i][j] = (grid[i][j]==0)?1:0;
        }
        return;
    }
    void flipcol(vector<vector<int>>& grid,int j,int m){
        for(int i=0;i<m;i++){
            grid[i][j] = (grid[i][j]==0)?1:0;
        }
        return;
    }
    int binarysum(vector<vector<int>>& grid,int m,int n,int &sum){
        for(int i = 0;i<m;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                sum += grid[i][j]*pow(2,count);
                count++;
            }
        }
        return sum;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[i][0] == 0){
                fliprow(grid,i,n);
            }
        }
        for(int j=1;j<n;j++){
            int count =0;
            for(int i=0;i<m;i++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
            if(count>m/2){
                flipcol(grid,j,m);
            }
        }
        int sum=0;
        return binarysum(grid,m,n,sum);
    }
};
