
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> xor_prefix(n + 1, 0);  // Initialize prefix XOR array with size n+1 and zeroes
        
        // Compute prefix XOR
        // xor_prefix[i+1] will hold the XOR of all elements from arr[0] to arr[i]
        for (int i = 0; i < n; ++i) {
            xor_prefix[i + 1] = xor_prefix[i] ^ arr[i];
        }
        
        int ans = 0;  // Variable to store the count of valid triplets
        
        // Check all sub-arrays
        // We iterate over all pairs of indices (i, j) where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                // If the XOR from the start to i is equal to the XOR from the start to j
                // It means the XOR of the sub-array from arr[i] to arr[j-1] is zero
                if (xor_prefix[i] == xor_prefix[j]) {
                    // Add the length of the sub-array minus one (j - i - 1) to the answer
                    ans += (j - i - 1);
                }
            }
        }
        
        return ans;  // Return the count of valid triplets
    }
};
