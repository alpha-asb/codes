class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if(!arr[0])return -1;
        int jump = arr[0];
        int mx = 0;
        int ans =1;
        for(int i=1;i<arr.size();i++){
            jump--;
            mx--;
            mx = max(mx,arr[i]);
            if(!jump && i != arr.size()-1){
                if(mx<=0)return -1;
                jump = mx;
                mx = 0;
                ans++;
            }
        }
        return ans;
    }
};
