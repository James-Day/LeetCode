//Time: O(M * N * 3^L) where m and n are the dimmensions of the board, and L is the length of the string. To understand this, think about the fact that it's possible to find 19 possible correct letters of a 20 character word, and then not find the final letter so you'd have to start over.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j) {
        if (word.size() == 0) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*'; // eleminate the character
        string newWord = word.substr(1); // remove first character
        bool ans = dfs(board, newWord, i - 1, j) || dfs(board, newWord, i + 1, j) || dfs(board, newWord, i, j - 1) || dfs(board, newWord, i, j + 1);
        board[i][j] = c;
        return ans;
    }
};