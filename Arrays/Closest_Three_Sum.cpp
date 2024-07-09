class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int mini=INT_MAX;
        int ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int s=arr[i]+arr[j]+arr[k];
                if(abs(s-target) < mini){
                    mini=abs(s-target);
                    ans=s;
                }
                else if(abs(s-target) == mini){
                    ans=max(ans,s);
                }
                
                if(s>target)
                    k--;
                else
                    j++;
                
            }
            
        }
        return(ans);
    }
    
};
