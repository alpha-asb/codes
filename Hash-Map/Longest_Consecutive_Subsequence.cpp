class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int>s;
      int mx = INT_MIN;
      for(int i=0;i<N;i++){
          mx = max(mx,arr[i]);
          s.insert(arr[i]);
      }
      int cnt = 0;
      int mx_cnt = 0;
      while(mx >=0 ){
          if(s.find(mx) != s.end()){
              cnt++;
              mx_cnt = max(mx_cnt,cnt);
          }
          else{
              cnt =0;
          }
          mx--;
      }
      return mx_cnt;
    }
};
