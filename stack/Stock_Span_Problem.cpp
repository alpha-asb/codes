class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int>res(arr.size(),1);
        stack<int>st;
        st.push(0);
        res[0] =1;
        for(int i=1;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            res[i] = (st.empty())?i+1:i-st.top();
            st.push(i);
        }
        return res;
    }
};
