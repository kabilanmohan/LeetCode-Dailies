
    /*
    Time complexity : O(m * n * 4 ^(length of string))
    Space complexity : O(length of string)
    */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        // Base case: found the word
        if (idx == word.size()) {
            return true;
        }

        // Boundary checks and character match check
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx]) {
            return false;
        }

        // Mark the cell as visited by altering its value
        char temp = board[row][col];
        board[row][col] = '.';

        // Recursively search in all four directions
        bool found = dfs(board, word, row + 1, col, idx + 1) ||  // south
                     dfs(board, word, row - 1, col, idx + 1) ||  // north
                     dfs(board, word, row, col + 1, idx + 1) ||  // east
                     dfs(board, word, row, col - 1, idx + 1);    // west

        // Restore the original value after backtracking
        board[row][col] = temp;

        return found;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/word-search/
    */

    