class Solution {
public:
    bool solve(int mid,vector<int>& bloomDay, int m, int k){
        int adj_flowers = 0;
        int bouquets =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                adj_flowers++;
            }
            else{
                adj_flowers =0;
            }
            if(adj_flowers == k){
                bouquets++;
                adj_flowers =0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int  maxi = INT_MIN;
        for(int num:bloomDay){
            maxi = max(maxi,num);
        }
        int ans=-1;
        int lo = 0;
        int hi = maxi;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(mid,bloomDay,m,k)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
