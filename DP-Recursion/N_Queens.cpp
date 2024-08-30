class Solution{
public:
    bool result = true;
    vector<int>rows;
    vector<vector<int>>res;
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>col(n,0);
        set<int>posDiagonal,negDiagonal;
        backtrack(0,board,col,posDiagonal,negDiagonal,n);
        return res;
    }
    void backtrack(int r,vector<vector<int>>&board,vector<int>&col,
     set<int>&posDiagonal,set<int>&negDiagonal,int n){
         if(r == n){
             res.push_back(rows);
             return;
         }
         for(int c =0;c<n;c++){
            if(col[c] == 1 || posDiagonal.find(r + c)!=posDiagonal.end() ||
            negDiagonal.find(r - c) != negDiagonal.end()){
                continue;
            }
            else{
               col[c] = 1;
               posDiagonal.insert(r+c);
               negDiagonal.insert(r-c);
               rows.push_back(c+1);
             
               backtrack(r+1,board,col,posDiagonal,negDiagonal,n);
               
               // backtracking
               col[c] = 0;
               posDiagonal.erase(r+c);
               negDiagonal.erase(r-c);
               rows.pop_back();
            }
        }
         
     }
};
