class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        
        int n = arr.size();
        int pos = 0;
        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                arr[pos] = arr[i];
                pos++;
            }
        }
        for(;pos<n;pos++){
            arr[pos] = 0;
        }
        
    }
};
