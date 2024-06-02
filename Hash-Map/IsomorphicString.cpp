class Solution {
public:
// index matching approach
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> map_s;
        map<char, int> map_t;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            char h = t[i];
            
            if (map_s.find(c) == map_s.end()) {
                map_s.insert(make_pair(c, i)); // Use the index as the value
            }

            if (map_t.find(h) == map_t.end()) {
                map_t.insert(make_pair(h, i)); // Use the index as the value
            }
            
            
            if (map_s[c] != map_t[h]) {
                return false;
            }
        }

        return true;
    }
};
