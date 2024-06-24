class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int val = 1;
        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0;
        int bottom =row-1;
        int left = 0;
        int right = col-1;
        
        while(top<=bottom && left<=right){
           
           // traversing top row
           for(int j = left;j<=right;j++){
            matrix[top][j] = val;
            val++;
           }
           top++;
           // traversing right col
           for(int i=top;i<=bottom;i++){
             matrix[i][right] = val;
             val++;
           }
           right--;
           // traversing bottom row
           if(top<=bottom){
           for(int j =right;j>=left;j--){
             matrix[bottom][j] = val;
             val++;
           }
           bottom--;
           }
           // traversing left col
           if(left<=right){
           for(int i=bottom;i>=top;i--){
             matrix[i][left] = val;
             val++;
           }
           left++;
           }
        }
        return matrix;
    }
};
