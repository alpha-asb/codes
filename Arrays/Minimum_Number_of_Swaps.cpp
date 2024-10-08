class Solution {
public:
    int minSwaps(string s) {
        int open = 0; // Count of '[' characters
        int close = 0; // Count of ']' characters
        int j = s.size() - 1; // Pointer from the end of the string
        int i = 0; // Pointer from the beginning of the string
        int swaps = 0; // To track the minimum number of swaps

        // Iterate through the string with two pointers
        while (i < j) {
            // If the character at i is '[', increment open counter
            if (s[i] == '[') {
                open++;
            } 
            // If the character at i is ']', increment close counter
            else {
                close++;
            }

            // If the number of close brackets exceeds open brackets
            if (open < close) {
                swaps++; // We need a swap to balance the string

                // Move j from the end until we find an open bracket '['
                while (s[j] == ']') {
                    j--;
                }
                j--; // Move j pointer after finding a '['

                // Adjust counts since we've conceptually swapped
                open++; // After the swap, we have one more open
                close--; // And one less close
            }

            // Move i to the next character in the string
            i++;
        }

        // Return the minimum number of swaps needed
        return swaps;
    }
};
