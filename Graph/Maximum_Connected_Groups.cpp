class Solution {
public:
    // Function to perform DFS and mark the connected components
    void dfs(vector<vector<int>>& grid, int i, int j, int component, int& count, vector<vector<pair<int, int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1; // mark as visited
        count++;
        dp[i][j] = {count, component};
        dfs(grid, i + 1, j, component, count, dp);
        dfs(grid, i - 1, j, component, count, dp);
        dfs(grid, i, j + 1, component, count, dp);
        dfs(grid, i, j - 1, component, count, dp);
    }

    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));
        int component = 0;
        vector<int> componentSizes;
        
        // Identify connected components and their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    component++;
                    dfs(grid, i, j, component, count, dp);
                    componentSizes.push_back(count);
                }
            }
        }

        int res = 0;
        
        // Calculate the maximum connection
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> componentsSeen;
                    int sum = 0;

                    if (i - 1 >= 0 && dp[i - 1][j].first != 0) {
                        int comp = dp[i - 1][j].second;
                        if (componentsSeen.find(comp) == componentsSeen.end()) {
                            sum += componentSizes[comp - 1];
                            componentsSeen.insert(comp);
                        }
                    }
                    if (i + 1 < n && dp[i + 1][j].first != 0) {
                        int comp = dp[i + 1][j].second;
                        if (componentsSeen.find(comp) == componentsSeen.end()) {
                            sum += componentSizes[comp - 1];
                            componentsSeen.insert(comp);
                        }
                    }
                    if (j - 1 >= 0 && dp[i][j - 1].first != 0) {
                        int comp = dp[i][j - 1].second;
                        if (componentsSeen.find(comp) == componentsSeen.end()) {
                            sum += componentSizes[comp - 1];
                            componentsSeen.insert(comp);
                        }
                    }
                    if (j + 1 < m && dp[i][j + 1].first != 0) {
                        int comp = dp[i][j + 1].second;
                        if (componentsSeen.find(comp) == componentsSeen.end()) {
                            sum += componentSizes[comp - 1];
                            componentsSeen.insert(comp);
                        }
                    }

                    res = max(res, 1 + sum);
                }
            }
        }

        // Check if the entire grid is filled with 1s
        if (res == 0 && !componentSizes.empty()) {
            res = componentSizes[0];
        }

        return res;
    }
};

