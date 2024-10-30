/*
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3)return 0;
        vector<int>v1(n,1),v2(n,1);
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                v1[i] = v1[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(arr[i-1] > arr[i]){
                v2[i-1] = v2[i]+1;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(v1[i] == 1 || v2[i] == 1){
                continue;
            }
            ans = max(ans,v1[i]+v2[i]-1);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3)return 0;
        int ans = 0;
        int base = 0;
        while(base < n){
            int end = base;
            if(end+1<n && arr[end+1]>arr[end]){
            while(end+1<n && arr[end+1]>arr[end]){
                end++;
            }
            if(end+1<n && arr[end+1]<arr[end]){
             while(end+1<n && arr[end+1]<arr[end]){
                end++;
             }
             ans = max(ans,end-base+1);
            }
        }
            base = max(end,base+1);
        }
        return ans;
    }
};
