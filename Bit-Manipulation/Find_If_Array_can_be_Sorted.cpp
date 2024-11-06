class Solution {
public:
    int setbit(int n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(n, 0);
        for (int i = 0; i < n; i++) {
            bits[i] = setbit(nums[i]);
        }

        // Bubble Sort with swap condition
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1] && bits[j] == bits[j + 1]) {
                   // return false;
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        // Check if the array is sorted
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) { // Corrected condition to check if sorted
                return false;
            }
        }
        return true; // Return true if sorted
    }
};
