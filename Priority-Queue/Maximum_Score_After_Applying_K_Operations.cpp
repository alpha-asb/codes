class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int>pq;
        for(int num:nums){
            pq.push(num);
        }
        while(k--){
            int val = pq.top();
            res += val;
            val = (val%3 == 0)?val/3:(val/3)+1;
            pq.pop();
            pq.push(val);
        }
        return res;
    }
};
