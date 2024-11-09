class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
       int n = arr.size();
       d = d%n;
       if(d == 0)return;
       reverse(arr.begin(),arr.end());
       reverse(arr.begin(),arr.begin()+n-d);
       reverse(arr.begin()+n-d,arr.end());
    }
};
