class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>>maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minHeap;

        int j=0;
        int left = 0,len = 0;
        while(j<nums.size()){
            maxHeap.push({nums[j],j});
            minHeap.push({nums[j],j});
            while(maxHeap.top().first-minHeap.top().first > limit){
                left = min(maxHeap.top().second,minHeap.top().second)+1;

                while(maxHeap.top().second < left){
                    maxHeap.pop();
                }
                while(minHeap.top().second < left){
                    minHeap.pop();
                }
            }
            len = max(len,j-left+1);
            j++;
        }
        return len;
    }
};
