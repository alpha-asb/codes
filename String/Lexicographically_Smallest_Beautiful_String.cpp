class Solution {
public:
    char FindNextValidChar(int i, const string &s, char limit, char start) {
        // Attempt the next valid character that doesn't conflict with previous characters
        while (start <= limit) {
            if ((i >= 1 && s[i - 1] == start) || (i >= 2 && s[i - 2] == start)) {
                start++;  // Conflict, so move to the next character
            } else {
                return start;  // Valid character found
            }
        }
        return limit + 1;  // If no valid character is found, return past the limit
    }

    string smallestBeautifulString(string s, int k) {
        char limit = 'a' + k - 1;
        int n = s.size();

        // Iterate from the end of the string to find the first modifiable position
        for (int i = n - 1; i >= 0; i--) {
            char nextChar = FindNextValidChar(i, s, limit, s[i] + 1);  // Start from s[i] + 1
            if (nextChar <= limit) {
                s[i] = nextChar;  // Modify the current position to the next valid character

                // Set remaining characters to the smallest valid options
                for (int j = i + 1; j < n; j++) {
                    s[j] = FindNextValidChar(j, s, limit, 'a');
                }
                return s;  // Return the result after constructing the valid string
            }
        }
        return "";  // No lexicographically larger beautiful string possible
    }
};
