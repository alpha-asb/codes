class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum =0;
        for(long long it:chalk){
            sum += it;
        }
        k = k%sum;
        int i =0;
        for(;i<chalk.size();i++){
            if(k < chalk[i]){
                break;
            }
            k -= chalk[i];
        }
        return i;
    }
};
