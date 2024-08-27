class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double cost = succProb[i];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        // djkstra Algoithm for maximum probability
        vector<double>dist(n,0.0);
        priority_queue<pair<double,int>>q;
        q.push({1.0,start_node});
        dist[start_node] = 0.0;

        while(!q.empty()){
            int node = q.top().second;
            double prob = q.top().first;
            q.pop();
            if(node == end_node){
                return prob;
            }
            for(auto vertex:adj[node]){
                int adjnode = vertex.first;
                double edgeprob = vertex.second;
                if(prob*edgeprob > dist[adjnode]){
                    dist[adjnode] = prob*edgeprob;
                    q.push({dist[adjnode],adjnode});
                }
            }
        }

        return 0.0;
    }
};
