class Solution
{
    public:
    // Function to find the smallest window in the string 's' consisting
    // of all the characters of the string 'p'.
    
    string smallestWindow (string s, string p)
    {
        // mp1 will store the frequency of each character in 'p'
        // mp2 will store the frequency of characters in the current window of 's'
        vector<int> mp1(26, 0), mp2(26, 0);
        
        // Fill the frequency map for string 'p'
        for (char c : p) {
            mp1[c - 'a'] += 1;
        }
        
        // i is the right pointer of the sliding window, j is the left pointer
        int i = 0, j = 0, idx = -1;
        
        // len will track the length of the smallest window found
        int len = INT_MAX;
        
        // cnt keeps track of how many characters from 'p' have been satisfied in the current window
        int cnt = 0;

        // Iterate over the string 's' using the right pointer 'i'
        while (i < s.size()) {
            // Add the current character at 'i' to the window (update its frequency in mp2)
            mp2[s[i] - 'a'] += 1;
            
            // If the current character is part of 'p' and we haven't exceeded the required frequency
            // (mp2[s[i] - 'a'] <= mp1[s[i] - 'a']), we count it towards satisfying the window.
            if (mp1[s[i] - 'a'] != 0 && mp2[s[i] - 'a'] <= mp1[s[i] - 'a']) {
                cnt++;  // A valid character for the window has been found.
            }
            
            // When all characters in 'p' are satisfied in the window (cnt equals p.size())
            while (cnt == p.size()) {
                // Check if this window is smaller than the previously found window
                if (len > i - j + 1) {
                    len = i - j + 1;  // Update the length of the smallest window
                    idx = j;          // Store the starting index of this window
                }
                
                // Shrink the window from the left by moving the left pointer 'j'
                mp2[s[j] - 'a'] -= 1;
                
                // If we remove a character that was part of the window, we need to reduce cnt
                // Only reduce cnt if the character removed was necessary for forming the window
                if (mp1[s[j] - 'a'] != 0 && mp2[s[j] - 'a'] < mp1[s[j] - 'a']) {
                    cnt--;  // A valid character has been removed, window is no longer valid
                }
                
                // Move the left pointer to shrink the window
                j++;
            }
            
            // Move the right pointer to expand the window
            i++;
        }
        
        // If no valid window was found, return "-1", else return the smallest window substring
        return (idx == -1) ? "-1" : s.substr(idx, len);
    }
};
