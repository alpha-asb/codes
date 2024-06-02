

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    
    long long countWays(int n) {
        // your code here
        long long res = (n/2)+1;
        return res;
    }
};
