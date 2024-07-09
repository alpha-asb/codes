class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int time = customers[0][0];
        double waiting = 0;
        for(int i=0;i<n;i++){
          time = max(time,customers[i][0]);
          time += customers[i][1];
          waiting += (time - customers[i][0]);
          cout<<time - customers[i][0]<<endl;
        }
        return double(waiting/n);
    }
};
