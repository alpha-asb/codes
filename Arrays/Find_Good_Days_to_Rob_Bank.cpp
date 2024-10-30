class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>a(n,1),b(n,1);
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                a[i] = a[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                b[i] = b[i+1]+1;
            }
        }
        vector<int>res;
        for(int i=time;i<n-time;i++){
            if(a[i]-1>=time && b[i]-1>=time){
                res.push_back(i);
            }
        }
        return res;
    }
};
