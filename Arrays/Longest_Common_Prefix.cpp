class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int len = INT_MAX;
        for(string str:arr){
            len = min(len,(int)str.length());
        }
        string prefix = "";
        for(int i=0;i<len;i++){
            char current = arr[0][i];
            for(string str:arr){
                if(str[i] != current){
                    return prefix.empty()?"-1":prefix;
                }
            }
            prefix += current;
        }
        return prefix.empty()?"-1":prefix;
    }
};
