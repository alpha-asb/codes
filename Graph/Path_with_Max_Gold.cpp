class Solution {
public:
    int max_sum = 0;

    bool isValid(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 0 && grid[i][j] != 0;
    }
    
    void DFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int sum, int i, int j) {
        visited[i][j] = 1;
        sum += grid[i][j];
        max_sum = max(max_sum, sum);  // Update max_sum after adding the current cell's value
        
        // Explore all four directions
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (isValid(grid, visited, ni, nj)) {
                DFS(grid, visited, sum, ni, nj);
            }
        }
        
        // Backtrack
        sum-=grid[i][j];
        visited[i][j] = 0;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    DFS(grid, visited, 0, i, j);
                }
            }
        }
        
        return max_sum;
    }
};
