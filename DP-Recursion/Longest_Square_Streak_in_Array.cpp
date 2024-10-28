class Solution {
public:
    int solve(int num, long long target, vector<int>& mp) {
        int count = 0;
        while (target <= 100000 && mp[target]) {
            count++;
            if (target > 31622) break;
            target *= target;
        }
        return count; 
    }

    int longestSquareStreak(vector<int>& nums) {
        vector<int> mp(100001, 0);
        int ans = 0;

        // Mark numbers in mp array
        for (int num : nums) {
            mp[num] = 1;
        }

        // Calculate longest square streak for each number
        for (long long num : nums) {
            if (num > 31622)continue;
            ans = max(ans, solve(num, num * num, mp));
        }

        return (ans == 0) ? -1 : ans + 1;
    }
};
