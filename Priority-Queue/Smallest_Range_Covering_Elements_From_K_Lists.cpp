class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int k = nums.size();
        int maxval =INT_MIN;
        
        for(int i=0;i<k;i++){
            maxval = max(maxval,nums[i][0]);
            pq.push({nums[i][0],i,0});  // minval , list , index
        }
        int left = pq.top()[0];
        int right = maxval;
        vector<int>res = {left,right};
        while(true){
            int val =  pq.top()[0];
            int list = pq.top()[1];
            int idx = pq.top()[2];
            pq.pop();
            idx++;
            if(idx == nums[list].size()){
                break;
            }
            int next_val = nums[list][idx];
            pq.push({next_val,list,idx});
            left = pq.top()[0];
            right = max(right,next_val);
            if(right - left < res[1] - res[0]){
                res = {left,right};
            }
        }
    return res;
    }
};
