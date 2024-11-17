class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        long long sum = 0;
        int len = INT_MAX;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum >= k){
                len = min(len,i+1);
            }
            while(!pq.empty() && sum - pq.top().first >=k){
                len = min(len,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return (len == INT_MAX)?-1:len;
    }
};
