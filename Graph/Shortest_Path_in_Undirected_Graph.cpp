class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
       vector<int>adj[N];
       for(int i =0;i<M;i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       vector<bool>vis(N,0);
       vector<int>res(N,-1);
       queue<int>q;
       q.push(src);
       vis[src] = 1;
       res[src] = 0;
       int dist = 0;
       while(!q.empty()){
           int size = q.size();
           for(int i = 0;i<size;i++){
               int node = q.front();
               q.pop();
               res[node] = dist;
               for(auto it: adj[node]){
                   if(!vis[it]){
                       vis[it] = 1;
                       q.push(it);
                   }
               }
               
           }
           dist++;
       }
       return res;
    }
};
