class Solution {
  public:
    int maxLength(string& str) {
        int n = str.size();  // Get the length of the input string
        int op = 0, cl = 0, res = 0;  // Initialize counters for open '(', close ')' and result

        // Left to right traversal
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                op++;  // Increment open parentheses counter
            } else {
                cl++;  // Increment close parentheses counter
            }

            if (cl > op) {  
                // If there are more closing parentheses, reset counters
                op = 0;
                cl = 0;
            } else if (op == cl) {
                // If open and close counts are equal, update the result with the maximum valid length
                res = max(res, 2 * op);
            }
        }

        // Reset the counters for right to left traversal
        op = 0;
        cl = 0;

        // Right to left traversal
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '(') {
                op++;  // Increment open parentheses counter
            } else {
                cl++;  // Increment close parentheses counter
            }

            if (cl < op) {
                // If there are more open parentheses, reset counters
                op = 0;
                cl = 0;
            } else if (op == cl) {
                // If open and close counts are equal, update the result with the maximum valid length
                res = max(res, 2 * op);
            }
        }

        return res;  // Return the maximum valid length
    }
};
