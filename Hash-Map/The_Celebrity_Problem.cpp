class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        /*
        Approach 1: O(n^2)Time and O(n) space
        int n = mat.size();
        int m = mat[0].size();
        vector<int>emptyRow;
        for(int row =0;row<n;row++){
            int cnt_0 = 0;
            for(int col =0;col<m;col++){
                if(mat[row][col] == 0)cnt_0++;
            }
            if(cnt_0 == m){
                emptyRow.push_back(row);
            }
        }
        for(int it:emptyRow){
            int cnt_1 = 0;
            for(int row = 0;row<n;row++){
                if(mat[row][it] == 1)cnt_1++;
            }
            if(cnt_1 == n-1)return it;
        }
        return -1;
        */
        // Approach 2: Optimal Approach:-> O(n) Time and O(1) Spacce
        
        int n = mat.size();
        
        int a = 0;
        int b = n-1;
        while(a<b){
            if(mat[a][b] == 1)a++;
            else b--;
        }
        // checking if a is actually a celebrity or not.
        for(int row =0;row<n;row++){
             // if any person doesn't know a or a knows any person, we return -1.
            if( row!=a && (mat[row][a] == 0 || mat[a][row] == 1))
              return -1;
        }
        return a;
    }
    
};
