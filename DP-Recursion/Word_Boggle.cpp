class Solution {
public:
    bool backtrack(int i, int n, string word, int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i] || vis[r][c]) {
            return false;
        }
        if (i == n - 1) {
            return true;
        }
        // Mark the current cell as visited
        vis[r][c] = 1;

        // Possible moves: right, left, down, up, top-right, top-left, bottom-right, bottom-left
        int rowMoves[8] = {0, 0, 1, -1, -1, -1, 1, 1};
        int colMoves[8] = {1, -1, 0, 0, 1, -1, 1, -1};

        for (int k = 0; k < 8; k++) {
            if (backtrack(i + 1, n, word, r + rowMoves[k], c + colMoves[k], board, vis)) {
                return true;
            }
        }

        // Unmark the current cell (backtrack)
        vis[r][c] = 0;

        return false;
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int n = board.size();
        int m = board[0].size();
        vector<string> res;

        for (int wordIdx = 0; wordIdx < dictionary.size(); wordIdx++) {
            vector<vector<int>> vis(n, vector<int>(m, 0)); // Reset visited array for each word
            bool found = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == dictionary[wordIdx][0]) {
                        if (backtrack(0, dictionary[wordIdx].size(), dictionary[wordIdx], i, j, board, vis)) {
                            res.push_back(dictionary[wordIdx]);
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
        }

        return res;
    }
};
