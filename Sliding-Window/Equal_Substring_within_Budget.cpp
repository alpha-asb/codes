class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>diff(n,0);
        for(int i=0;i<n;i++){
           diff[i] = abs(s[i]-t[i]);
        }
        int ans =0;
        int i = 0;
        int j = 0;
        int sum =0;
        while(i<n && j<n){
           sum+=diff[j];
            
            while(sum>maxCost && i<=j ){
                sum-=diff[i];
                i++;
             }
           
           ans = max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};
