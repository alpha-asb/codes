class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int>left(n,0),right(n,0);
        left[0] = arr[0];
        for(int i=1;i<n;i++){
            left[i] = min(left[i-1],arr[i]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        vector<int>res;
        for(int i=1;i<n-1;i++){
            if(left[i] < arr[i] && arr[i] < right[i]){
                res = {left[i],arr[i],right[i]};
                break;
            }
        }
        return res;
    }
};
