/*
class Solution {
public:
    const long long mod = 1e9 + 7;

    long long solve(int A_count, int L_count, int n, vector<vector<vector<long long>>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][A_count][L_count] != -1) {
            return dp[n][A_count][L_count];
        }

        long long res = 0;
        // Present P: append P
        res = (res + solve(A_count, L_count, n - 1, dp)) % mod;
        // Absent A: append A
        if (A_count == 0) {
            res = (res + solve(A_count + 1, L_count, n - 1, dp)) % mod;
        }
        // Late L: append L if not late for consecutive 2 days
        if (L_count < 2) {
            res = (res + solve(A_count, L_count + 1, n - 1, dp)) % mod;
        }

        return dp[n][A_count][L_count] = res;
    }

    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(3, -1)));
        return solve(0, 0, n, dp);
    }
};
*/

class Solution {
public:
    const long long mod = 1e9+7;
    long long dp[100001][2][3];
    long long f(int i, int absent, int late)
    {
        if(absent>=2 || late>=3)
        {
            return 0;
        }
        if(i==0)
        {
            return 1;
        }
        if(dp[i][absent][late]!=-1)
        {
            return dp[i][absent][late];
        }

        long long ans=f(i-1, absent, 0);
        ans = ans + (late<2?f(i-1, absent, late+1):0);
        ans = ans + (absent==0?f(i-1, absent+1, 0):0);
       
        return dp[i][absent][late]=ans%mod;
    }
    int checkRecord(int n)
    {
        fill(&dp[0][0][0], &dp[0][0][0]+(n+1)*6, -1);
        return f(n, 0, 0);
    }
};
