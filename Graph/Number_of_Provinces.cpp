class Solution {
public:
    void dfs(int s,int n,vector<vector<int>>& isConnected,vector<int>&visited){
        visited[s]=true;
        vector<int>adj;

        for(int i=0;i<n;i++){
            if(isConnected[s][i]==1){
                adj.push_back(i);
            }
        }
        for(auto x:adj){
           if(!visited[x]){
               dfs(x,n,isConnected,visited);
           }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,n,isConnected,visited);
            }
        }
        return count;
    }
};
