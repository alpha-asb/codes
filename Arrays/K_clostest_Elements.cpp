class Solution {
  public:
    int binary(vector<int> arr, int n, int x){
        int start =0;
        int end = n-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr[mid]<=x && arr[mid+1]>x){
                return mid;
            }
            else if(arr[mid]>x){
                end = mid-1 ;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int>res;
        int i = binary(arr,n,x);
        // cout<<"mid:"<<arr[i];
        int right = i+1;
        int left = i;
        if(arr[i]==x){
            left--;
        }
        while(k--){
            int l_val = INT_MAX,r_val = INT_MAX;
            if(right<n){
                r_val = arr[right]-x;
            }
            if(left>=0){
                l_val = x - arr[left];
            }
            
            if(l_val<r_val){
                res.push_back(arr[left]);
                left--;
            }
            else{
                res.push_back(arr[right]);
                right++;
            }
        }
        return res;
    }
};
