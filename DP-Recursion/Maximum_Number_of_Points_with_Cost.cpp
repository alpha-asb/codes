class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> prevRow(m,0);
        
        // Initialize the first row
        for (int col = 0; col < m; col++) {
            prevRow[col] = points[0][col];
        }
        
        // Fill the dp table
        for (int row = 1; row < n; row++) {
            vector<long long> left_max(m, 0);
            vector<long long> right_max(m, 0);
            vector<long long>currRow(m,0);
            
            // Fill left_max
            left_max[0] = prevRow[0];
            for (int col = 1; col < m; col++) {
                left_max[col] = max(left_max[col-1]-1, prevRow[col]);
            }
            
            // Fill right_max
            right_max[m-1] = prevRow[m-1];
            for (int col = m-2; col >= 0; col--) {
                right_max[col] = max(right_max[col+1]-1, prevRow[col]);
            }
            
            // Fill current dp row
            for (int col = 0; col < m; col++) {
                currRow[col] = points[row][col] + max(left_max[col], right_max[col]);
                prevRow = currRow;
            }
        }
        
        // Find the maximum in the last row
        long long res = 0;
        for (int col = 0; col < m; col++) {
            res = max(res, prevRow[col]);
        }
        
        return res;
    }
};
