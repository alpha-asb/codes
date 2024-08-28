class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
       unordered_map<int,int>mp;
       for(int num : arr){
           mp[num]++;
       }
       vector<pair<int,int>>v;
       for(auto it:mp){
           v.push_back({it.first,it.second});
       }
       sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
           if(a.second == b.second){
               return a.first < b.first;
           }
           else{
               return a.second > b.second;
           }
       });
       vector<int>res;
       for(auto it:v){
           int num = it.first;
           int cnt = it.second;
           for(int i=0;i<cnt;i++){
               res.push_back(num);
           }
       }
       return res;
    }
};
