class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first = edges[0][0];
        int second = edges[0][1];

        return (first == edges[1][0] || first == edges[1][1])?first:second;
    }
};
