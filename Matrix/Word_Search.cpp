
class Solution {
public:
    bool dfs(int i, int j, int idx, const string& word, vector<vector<char>>&board, int m, int n, set<pair<int, int>>&visited) {
        if (idx == word.size()) {
            return true; // Word found
        }
        if (i < 0 || j < 0 || i >= m || j >= n || word[idx] != board[i][j] || visited.find({i, j}) != visited.end()) {
            return false; // Out of bounds or already visited or mismatch
        }
        visited.insert({i, j});
        bool res = dfs(i + 1, j, idx + 1, word, board, m, n, visited) ||
                   dfs(i, j + 1, idx + 1, word, board, m, n, visited) ||
                   dfs(i - 1, j, idx + 1, word, board, m, n, visited) ||
                   dfs(i, j - 1, idx + 1, word, board, m, n, visited);
        visited.erase({i, j});
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        set<pair<int, int>> visited;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, board, m, n, visited)) {
                    return true; // Word found, no need to continue searching
                }
            }
        }
        return false; // Word not found
    }
};
