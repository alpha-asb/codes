class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
      /*
        //Approach 1 : O(n*m) Time
        int m = arr.size();
        int n = arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[j][i] == 1)return j;
            }
        }
        return -1;
    }
    */
      
      // Optimal appraoch: O(n+m) Time
      // start from top right corner if the element is 1 move left
      // if the element is 0 move down
      // in this way we can find the answer in optimal way;
    
      int row = 0;
      int col = arr[0].size()-1;
      int m = arr.size();
      int res = -1;
      while(row < m && col >=0){
          if(arr[row][col] == 1){
              res = row;
              col--;
          }
          else{
              row++;
          }
      }
      return res;
    }
};
