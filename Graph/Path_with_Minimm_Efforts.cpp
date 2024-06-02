class Solution {
  public:
    // int min_diff = INT_MAX;
    
    // bool isValid(vector<vector<bool>>& visited, int i, int j,int row,int col) {
        
    //     return i >= 0 && i < row && j >= 0 && j < col && visited[i][j] == false;
    // }
    // void DFS(vector<vector<int>> &heights,vector<vector<bool>>&visited,int i,int j,int row,int col,int diff,int prev){
    //     visited[i][j] = true;
    //     int curr_diff = max(diff,abs(heights[i][j]-prev));
    //     if(i == row-1 && j == col-1){
    //         min_diff = min(min_diff,curr_diff);
    //         visited[i][j] = false;
    //         return;
    //     }
    //     int x_new[] = {-1,1,0,0};
    //     int y_new[] = {0,0,1,-1};
    //     for(int k=0;k<4;k++){
    //         int x_row = i+x_new[k];
    //         int y_col = j+y_new[k];
            
    //         if(isValid(visited,x_row,y_col,row,col)){
    //             DFS(heights,visited,x_row,y_col,row,col,curr_diff,heights[i][j]);
    //         }
    //     }
    //     visited[i][j] = false;
        
        
    // }
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
       priority_queue<pair<int,pair<int,int>>,
       vector<pair<int,pair<int,int>>>,
       greater<pair<int,pair<int,int>>>>heap;
       
       vector<vector<int>>dp(rows,vector<int>(columns,INT_MAX));
       dp[0][0] = 0;
       heap.push({0,{0,0}});
       int x_d[]={-1,0,1,0};
       int y_d[]={0,-1,0,1};
       while(!heap.empty()){
           auto it = heap.top();
           heap.pop();
           int diff = it.first;
           int x = it.second.first;
           int y = it.second.second;
           
           if(x == rows-1 && y == columns-1){
               return diff;
           }
           for(int i=0;i<4;i++){
               int row = x + x_d[i];
               int col = y + y_d[i];
               
               if(row >= 0 && row<rows && col >=0 && col<columns){
                  int new_diff  = max(abs(heights[x][y] -heights[row][col]),diff);
                  if(new_diff < dp[row][col]){
                      dp[row][col] = new_diff;
                      heap.push({new_diff,{row,col}});
                  }
               }
           }
       }
       return 0;
    }
};
