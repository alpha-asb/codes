class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            if(a.second != b.second){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        vector<int>res;
        for(auto it:v){
           for(int i=0;i<it.second;i++){
            res.push_back(it.first);
           }
        }
        return res;
    }
};
