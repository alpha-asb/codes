
class DSU {
public:
    vector<int> parent;
    DSU() {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);  // Path compression
    }
    
    void Union(int u, int v) {
        int par_u = findParent(u);
        int par_v = findParent(v);
        if (par_u < par_v) {
            parent[par_v] = par_u;  // Make the smaller root the parent
        } else if (par_u > par_v) {
            parent[par_u] = par_v;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU ds;

        for (int i = 0; i < s1.size(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.Union(u, v);
        }
        
        string res = "";
        for (int i = 0; i < baseStr.size(); i++) {
            int x = baseStr[i] - 'a';
            x = ds.findParent(x);
            char c = char(x + 'a');
            res += c;
        }
        
        return res;
    }
};
