class Solution {
  public:
    vector<string>res;
    void solve(vector<vector<int>> &mat,vector<vector<bool>>&visited,int i,int j,string temp,int n,int m){
      if(i<0 || i>= n || j<0 || j>=m || visited[i][j] == true || mat[i][j] == 0)return;
      visited[i][j] = true;
      if(i == n-1 && j == m-1){res.push_back(temp);}
      solve(mat,visited,i+1,j,temp +'D',n,m);
      solve(mat,visited,i,j+1,temp +'R',n,m);
      solve(mat,visited,i-1,j,temp +'U',n,m);
      solve(mat,visited,i,j-1,temp +'L',n,m);
      visited[i][j] = false;
      temp = temp.substr(0,temp.size()-1);
      
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        string temp ="";
        if(mat[0][0] == 0)return res;
        solve(mat,visited,0,0,temp,n,m);
        sort(res.begin(),res.end());
        return res;
    }
};
