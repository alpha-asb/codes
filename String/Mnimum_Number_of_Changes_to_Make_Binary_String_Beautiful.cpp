/*
You are given a 0-indexed binary string s having an even length.

A string is beautiful if it's possible to partition it into one or more substrings such that:

Each substring has an even length.
Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1.

Return the minimum number of changes required to make the string s beautiful.

For any valid partition, since each part consists of an even number of the same characters, we can further partition each part into lengths of exactly 2.

After noticing the first hint, we can decompose the whole string into disjoint blocks of size 2 and find the minimum number of changes required to make those blocks beautiful.
*/

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans =0;
        for(int i=0;i<n-1;i+=2){
           if(s[i] == s[i+1]){
            continue;
           }
           else{
            ans++;
           }
        }
        return ans;
    }
};
