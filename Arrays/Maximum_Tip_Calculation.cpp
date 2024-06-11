
class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // Create a 2D vector A
        vector<vector<int>> A(n, vector<int>(3, 0));

        // Populate A
        for (int i = 0; i < n; ++i) {
            A[i][0] = arr[i];
            A[i][1] = brr[i];
            A[i][2] = abs(arr[i] - brr[i]);
        }

        // Define the custom comparator as a lambda function
        auto customComparator = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2]; // Sort in descending order based on the absolute difference
        };

        // Sort A using the custom comparator
        sort(A.begin(), A.end(), customComparator);

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (x == 0) {
                ans += A[i][1];
                --y;
            } else if (y == 0) {
                ans += A[i][0];
                --x;
            } else {
                if (A[i][0] > A[i][1]) {
                    ans += A[i][0];
                    --x;
                } else {
                    ans += A[i][1];
                    --y;
                }
            }
        }

        return ans;
    }
};
