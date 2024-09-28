class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        long long pos = arr[0];
        long long neg = arr[0];
        long long res = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] < 0){
                swap(pos,neg);
            }
            pos = max((long long)arr[i],pos*arr[i]);
            neg = min((long long)arr[i],neg*arr[i]);
            res = max(res,pos);
        }
        return res;
    }
};
