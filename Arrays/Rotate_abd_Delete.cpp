class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
      int n = arr.size();
      int temp = n/2;
      int i = 3*(temp/2);
      if(temp%2)i++;
      return arr[n-i];
    }
};

// class Solution {
//   public:
//     int rotateDelete(vector<int> &arr) {
//         int i = 1;
//         int n = arr.size();
//         while (i < (n / 2) + 1) {
//             // rotating the array
//             rotate(arr.begin(), arr.end() - 1, arr.end());
//             // delete (z-k+1)th element
//             arr.erase(arr.begin() + (arr.size() - i));
//             i++;
//         }
//         return arr[0];
//     }
// };
