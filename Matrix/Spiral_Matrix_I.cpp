class Solution {
public:
// Approach : 4 direction traversal with shrinking the boundries

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom =m-1;
        int left = 0;
        int right = n-1;
        
        vector<int>ans;
        while(top<=bottom && left<=right){
           
           // traversing top row
           for(int j = left;j<=right;j++){
            ans.push_back(matrix[top][j]);
           }
           top++;
           // traversing right col
           for(int i=top;i<=bottom;i++){
             ans.push_back(matrix[i][right]);
           }
           right--;
           // traversing bottom row
           if(top<=bottom){
           for(int j =right;j>=left;j--){
             ans.push_back(matrix[bottom][j]);
           }
           bottom--;
           }
           // traversing left col
           if(left<=right){
           for(int i=bottom;i>=top;i--){
             ans.push_back(matrix[i][left]);
           }
           left++;
           }
        }
        return ans;
    }
};
