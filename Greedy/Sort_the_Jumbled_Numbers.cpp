class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,pair<int,int>>>mp;
        for(int i =0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            string new_num = "";
            for(auto c:temp){
                int digit = c - '0';
                int new_digit = mapping[digit];
                new_num +=  to_string(new_digit);
            }
            // int j=0;
            // while(new_num[j] == '0'){
            //     new_num = new_num.substr(1);
            //     j++;
            // }
            mp.push_back({stoi(new_num),{nums[i],i}});
        }
        sort(mp.begin(),mp.end(),[](pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
            if(a.first == b.first){
                return a.second.second < b.second.second;
            }
            else{
                return a.first < b.first;
            }
        });

        vector<int>res;
        for(auto it:mp){
            res.push_back(it.second.first);
        }
        return res;
    }
};
