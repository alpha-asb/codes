class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        
        int sum_a = 0;
        int sum_b = 0;
        for (int i = 0; i < n; i++) {
            sum_a += a[i];
        }
        for (int i = 0; i < m; i++) {
            sum_b += b[i];
        }

        // If the difference is not even, we cannot find such pairs
        if ((sum_a - sum_b) % 2 != 0) {
            return -1;
        }

        int target_diff = (sum_a - sum_b) / 2;

        // Use a hash set to store elements of array a
        std::unordered_set<int> set_a(a, a + n);

        // Find an element in b that satisfies the condition
        for (int i = 0; i < m; i++) {
            if (set_a.count(b[i] + target_diff)) {
                return 1; // Pair found
            }
        }

        // If no such pair is found
        return -1;

    }
};
