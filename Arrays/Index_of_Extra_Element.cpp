class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int l=0;
        int r=n-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr1[m]==arr2[m]){
                l = m+1;
            }
            else if(arr1[m]!=arr2[m]){
                r= m-1;
            }
        }
        return l;
    }
};
