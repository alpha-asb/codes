class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int repeat=-1,missing=arr.size();
        for(int i=0;i<arr.size();i++){
            int val = abs(arr[i]);
            if(arr[val-1] < 0){
                repeat = val;
            }
            else{
                arr[val-1] = -1*arr[val-1];
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i] > 0){
                missing = i+1;
                break;
            }
        }
        return {repeat,missing};
    }
};
