class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // DP table to store max path length starting from each cell
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;

        // Fill the dp table starting from the last column and last row
        for (int j = m - 2; j >= 0; j--) {  // Start from the second-last column and move left
            for (int i = n - 1; i >= 0; i--) {  // Start from the last row and move up
                int right = (grid[i][j] < grid[i][j + 1]) ? dp[i][j + 1] + 1 : 0;
                int upRight = (i > 0 && grid[i][j] < grid[i - 1][j + 1]) ? dp[i - 1][j + 1] + 1 : 0;
                int downRight = (i < n - 1 && grid[i][j] < grid[i + 1][j + 1]) ? dp[i + 1][j + 1] + 1 : 0;

                // Store the maximum path length starting from cell (i, j)
                dp[i][j] = max({right, upRight, downRight});
            }
        }

        // Calculate the longest path by taking the maximum in the first column
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};
