class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int num[1001];
        for(int i=0;i<target.size();i++){
            num[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            num[arr[i]]--;
        }
        for(int i=0;i<1001;i++){
            if(num[i] != 0)return false;
        }
        return true;
    }
};
