/*
O(n) Time and O(n) Space


class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
       unordered_set<int>mp;
       for(int n:arr){
           if(n>0){
               mp.insert(n);
           }
       }
       int res = 1;
       while(mp.find(res) != mp.end()){
           res++;
       }
       return res;
    }
};
*/

// Optimized : O(n)time and O(1) Space

// 1. Segrigate the array
// 2. do negating index on segrigated array
// 3. run a loop and return the first index having val > 0   (intialize to n+1, since if all th val
//     val present n+1 will be the smallest missing)

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int segrigate(vector<int> &arr){
        int i=0;
        int j=0;
        for(;i<arr.size();i++){
            if(arr[i]<=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        return j; //  index from where positive values 
    } 
    int missingNumber(vector<int> &arr) {
      // negating index
      int shift = segrigate(arr);
      
              // Mark the indices for positive numbers
      for (int i = shift; i < arr.size(); i++) {
            int val = abs(arr[i]);
            // Ensure index is within bounds before marking
            if (val - 1 + shift < arr.size() && arr[val - 1 + shift] > 0) {
                arr[val - 1 + shift] = -arr[val - 1 + shift];  // Mark as visited
            }
        }
      for(int i = shift;i<arr.size();i++){
          if(arr[i] > 0){
              return i-shift+1;
          }
      }
          return arr.size()-shift+1;
    }
};
