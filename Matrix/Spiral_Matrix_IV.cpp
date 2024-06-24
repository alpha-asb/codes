class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0;
        int bottom =row-1;
        int left = 0;
        int right = col-1;
        
        while(top<=bottom && left<=right && head){
           
           // traversing top row
           for(int j = left;j<=right && head;j++){
            matrix[top][j] = head->val;
            head = head->next;
           }
           top++;
           // traversing right col
           for(int i=top;i<=bottom && head;i++){
             matrix[i][right] = head->val;
            head = head->next;
           }
           right--;
           // traversing bottom row
           if(top<=bottom){
           for(int j =right;j>=left && head;j--){
             matrix[bottom][j] = head->val;
            head = head->next;
           }
           bottom--;
           }
           // traversing left col
           if(left<=right){
           for(int i=bottom;i>=top && head;i--){
             matrix[i][left] = head->val;
             head = head->next;
           }
           left++;
           }
        }
        return matrix;
    }
};
