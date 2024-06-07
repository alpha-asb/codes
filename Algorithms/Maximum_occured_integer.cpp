class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
     // Brutt Force Approach : O(n^2)
     
     /*   // Your code here
        int arr[maxx+1]={0};
        for(int i=0;i<n;i++){
            for(int j = l[i];j<=r[i];j++){
                arr[j]++;
            }
        }
         // Find the index with the maximum count
    int maxCount = arr[0];
    int ans = 0;
    for (int i = 1; i <= maxx; i++) {
        if (arr[i] > maxCount) {
            maxCount = arr[i];
            ans = i;
        }
    }
        return ans;
    */
    
    // Approach 2: O(n) Optimized, prefix sum approach
    
    int arr[maxx+2] = {0};
    
    for(int i=0;i<n;i++){
        arr[l[i]]++;     // from where frequency start increasing
        arr[r[i]+1]-- ;   // from where frequency start decreasing
    }
    int freq = arr[0];
    int ans =0;
    for(int i=1;i<=maxx;i++){
        arr[i]+=arr[i-1];
        if(arr[i]>freq){
            freq = arr[i];
            ans = i;
        }
    }
    return ans;
    }
};
