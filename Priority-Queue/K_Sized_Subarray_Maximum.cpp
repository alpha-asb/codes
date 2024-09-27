class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        vector<int>res;
        deque<int>dq;
        int i=0;
        for(;i<k;i++){
            while(!dq.empty() and arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<arr.size();i++){
            res.push_back(arr[dq.front()]);
            
            // remove out of wndow index
            while(!dq.empty() and dq.front() <= i-k){
                dq.pop_front();
            }
            // processing back to only have increasing sequence 
            while(!dq.empty() and arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            // push current index
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        return res;
    }
};
