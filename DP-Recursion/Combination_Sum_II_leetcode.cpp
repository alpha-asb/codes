class Solution {
    private:
    void solve(int target,int idx,vector<int>& candidates,vector<vector<int>>&res,vector<int>&temp){
           
           if(target == 0){
            res.push_back(temp);
            return;
           }
           for(int i = idx; i<candidates.size() && candidates[i] <= target;i++){
           
             if(i == idx || candidates[i] != candidates[i-1]){

             temp.push_back(candidates[i]);
             solve(target-candidates[i],i+1,candidates,res,temp);
             temp.pop_back();
             }
            }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        solve(target,0,candidates,res,temp);
        return res;
    }
};
