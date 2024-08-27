class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int>left(n,0),right(n,0);
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            left[i] = (st.empty())?0:st.top();
            st.push(arr[i]);
        }
        while(!st.empty()){st.pop();}
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            right[i] = (st.empty())?0:st.top();
            st.push(arr[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,abs(left[i]-right[i]));
        }
        return ans;
    }
};
