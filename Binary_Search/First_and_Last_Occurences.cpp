class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int lo = 0;
        int hi = n-1;
        int mid;
        bool flag = false;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid] == x){
                flag =true;
                break;
            }
            else if(arr[mid] < x){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        if(!flag){
            return {-1,-1};
        }
        int first = mid;
        int second =mid;
        
        lo = 0;
        hi= mid;
        while(lo <= hi){
            int mid2 = lo + (hi-lo)/2;
            if(arr[mid2] == arr[mid]){
                first = mid2;
                hi = mid2-1;
            }
            else{
                lo = mid2+1;
            }
        }
        lo = mid;
        hi = n-1;
        while(lo<=hi){
            int mid3 = lo + (hi-lo)/2;
            if(arr[mid3] == arr[mid] ){
                second = mid3;
                lo = mid3+1;
            }
            else{
                hi = mid3-1;
            }
        }
        return {first,second};
    }
};
