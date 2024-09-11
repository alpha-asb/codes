class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        int n =arr.size();
        for(auto num:arr){
            pq.push(num);
        }
        long long ans =0;
        while(pq.size()>1){
            long long a = pq.top();pq.pop();
            long long b = pq.top();pq.pop();
            ans += (a+b);
            pq.push(a+b);
        }
        return ans;
    }
};
