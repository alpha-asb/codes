class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int pivot = n;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pivot = i;
                break;
            }
            
        }
        if(pivot == n){
           reverse(arr.begin(),arr.end());
           return;
        }
        int idx,mini = INT_MAX;
        for(int i=pivot+1;i<n;i++){
            if(arr[i]>arr[pivot] && arr[i]<mini){
                mini = arr[i];
                idx = i;
            }
        }
        swap(arr[pivot],arr[idx]);
        sort(arr.begin()+pivot+1,arr.end());
    } 
};
