class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.' && seen.contains(board[i][j])) {
                    return false;
                }
                seen.insert(board[i][j]);
            }
            seen.clear();
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] != '.' && seen.contains(board[j][i])) {
                    return false;
                }
                seen.insert(board[j][i]);
            }
            seen.clear();
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[(i * 3) + k][(j * 3) + l] != '.' && seen.contains(board[(i * 3) + k][(j * 3) + l])) {
                            return false;
                        }
                        seen.insert(board[(i * 3) + k][(j * 3) + l]);
                    }
                }
                seen.clear();
            }
        }


        return true;

    }
};