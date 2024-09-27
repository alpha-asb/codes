class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int,int>s;
        for(int n:nums){
            int need = k - n%k;            // heart of problem : finding pair for the current element
            if(s.find(need)!=s.end()){     // if found remove one count of need and erase if count =0
                s[need]--;
                if(s[need] == 0){    
                    s.erase(need);
                }
            }
            else{                          //  insert k for number itself divisible by k, since for pair it will need 0,k
                s[((n%k==0)?k:n%k)]++;     // insert in map to find pair in future
            }
        }
        return s.empty();
    }
};
