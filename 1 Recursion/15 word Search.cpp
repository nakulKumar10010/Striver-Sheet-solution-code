class Solution {
public:
    bool find(vector<vector<char>>& board, string word, int i, int j, int row,
              int col, int ind) {
        // full word matched
        if (ind == word.size())
            return true;
        // out of boundary || word not found || already visited('$') thats mean
        // failed recursion
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] == '$' ||
            board[i][j] != word[ind])
            return false;

        char temp = board[i][j]; // saving the element for backtracking
        board[i][j] = '$';       // make visited
        // recursion L R U D
        bool found = find(board, word, i, j - 1, row, col, ind + 1) ||
                     find(board, word, i, j + 1, row, col, ind + 1) ||
                     find(board, word, i - 1, j, row, col, ind + 1) ||
                     find(board, word, i + 1, j, row, col, ind + 1);
        // backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        //do function call whenever first cahracter found
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0] &&
                    find(board, word, i, j, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
