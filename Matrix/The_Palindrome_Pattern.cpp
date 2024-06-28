class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int r = n-1;
            bool isPalindromeR = true;
            for(int l =0;l < n/2;l++){
                if(arr[i][l] != arr[i][r]){
                    isPalindromeR = false;
                    break;
                }
                r--;
            }
            
            if(isPalindromeR){
                string res = to_string(i)+" "+"R";
                return res;
            }
        }
        for(int i=0;i<n;i++){
            int r = n-1;
            bool isPalindromeC = true;
            for(int l =0;l < n/2;l++){
                if(arr[l][i] != arr[r][i]){
                    isPalindromeC = false;
                    break;
                }
                r--;
            }
            if(isPalindromeC){
                string res = to_string(i)+" "+"C";
                return res;
            }
        }
        return "-1";
    }
};
