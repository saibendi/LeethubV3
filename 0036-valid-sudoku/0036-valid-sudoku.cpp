class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols; 
        map<pair<int,int>, unordered_set<int>> squares; 

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                pair<int,int> square_key = {r / 3, c / 3};
                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || 
                squares[square_key].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[square_key].insert(board[r][c]);   
            }
        }
        return true; 
    }
};