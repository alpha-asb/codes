class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int sum =0;
        for(int it:arr){
            sum+=it;
        }
        if(sum%3 != 0){return {-1,-1};}
        int curr = 0,firstidx = -1,secondidx =-1;
        int ptr = 0;
        while(ptr<arr.size()){
            curr += arr[ptr];
            if(3*curr == sum){
                firstidx = ptr;
                ptr++;
                break;
            }
            else if(3*curr > sum){
                return {-1,-1};
            }
            else{
                ptr++;
            }
        }
        curr = 0;
        while(ptr<arr.size()){
            if(3*curr == sum){
                secondidx = ptr;
                ptr++;
                break;
            }
            else if(3*curr > sum){
                return {-1,-1};
            }
            else{
                ptr++;
            }
        }
        curr = 0;
        while(ptr<arr.size()){
            curr += arr[ptr];
            ptr++;
        }
        if(curr*3 == sum){
            return {firstidx,secondidx};
        }
        return {-1,-1};
    }
};
