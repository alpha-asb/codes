

class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=arr[i];
        }
        return ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[arr[i]]++;
        // }
        // for(auto x:mp){
        //     if(x.second%2!=0){
        //         return x.first;
        //     }
        // }
        // return -1;
    }
};

