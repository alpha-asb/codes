class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        visited[0][0] = 1;
        int dir[4] = {0,1,0,-1};
        int dic[4] = {1,0,-1,0};
        while(!pq.empty()){
            auto it = pq.top();
            int time = it[0];
            int row = it[1];
            int col = it[2];
            pq.pop();
            if(row == n-1 && col == m-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int new_r = row + dir[i];
                int new_c = col + dic[i];
                int val = 2 - (new_r + new_c)%2;  // parity check crusial step
                if(new_r >= 0 && new_r <n && new_c >=0 && new_c <m && !visited[new_r][new_c]){
                    pq.push({val + max(time,moveTime[new_r][new_c]),new_r,new_c});
                    visited[new_r][new_c] = 1;
                }
            }
        }
        return -1;
    }
};
