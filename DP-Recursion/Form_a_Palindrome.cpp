class Solution {
public:
    int countMin(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // All substrings of length 1 are palindromes of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Build the dp table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of the longest palindromic subsequence
        int lps = dp[0][n - 1];

        //cout<<n<<endl;
        return n - lps;
    }
};
