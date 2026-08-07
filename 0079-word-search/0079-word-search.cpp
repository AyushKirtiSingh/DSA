class Solution {
public:
    bool wordsearch(vector<vector<char>>& board, string word, int r, int c, int i) {
        int n = board.size();
        int m = board[0].size();

        // Base Case:
        // 1. Out of boundary
        // 2. Cell already visited
        // 3. Current character doesn't match the required character
        if (r < 0 || c < 0 || r >= n || c >= m ||
            board[r][c] == '#' || board[r][c] != word[i]) {
            return false;
        }

        // Agar pura word match ho jata hai
        if (i == word.length() - 1) {
            return true;
        }

        // Original character ko store karta hai before marking visited
        char temp = board[r][c];

        // Mark current cell as visited
        board[r][c] = '#';

        // Explore all 4 directions
        bool ans1 = wordsearch(board, word, r + 1, c, i + 1); // Down
        bool ans2 = wordsearch(board, word, r - 1, c, i + 1); // Up
        bool ans3 = wordsearch(board, word, r, c + 1, i + 1); // Right
        bool ans4 = wordsearch(board, word, r, c - 1, i + 1); // Left

        // Backtrack: restore original character
        board[r][c] = temp;

        // If any path returns true, word exists
        return (ans1 || ans2 || ans3 || ans4);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Har cell ko as starting point try karta h
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start DFS agar pehla charachter of word milta hai (optional optimization)
                if (board[i][j] == word[0] && wordsearch(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        // Word not found
        return false;
    }
};