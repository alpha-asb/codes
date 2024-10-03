class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){return {nums[0]};}
        int n1 ,n2;
        int counter1 = 0, counter2 = 0;
        
        for(int i = 0;i<n;i++){
            if(nums[i] == n1){
                counter1++;
            }
            else if(nums[i] == n2){
                counter2++;
            }
            else if(counter1 == 0){
                n1 = nums[i];
                counter1++;
            }
            else if(counter2 == 0){
                n2 = nums[i];
                counter2++;
            }
            else{
                counter1--;
                counter2--;
            }
        }
        int votes1 = 0,votes2 = 0;
        for(int x:nums){
            if(x == n1){
                votes1++;
            }
            else if(x == n2){
                votes2++;
            }
        }
        vector<int>res;
        if(votes1 > n/3){res.push_back(n1);}
        if(votes2 > n/3){res.push_back(n2);}
        if(res.size() == 0){res.push_back(-1);}
        return res;
    }
};
