class Solution {
public:
    // Perform DFS to mark all 'O's connected to the border
    void dfs(vector<vector<int>>& visited, vector<vector<char>>& board, int row,
             int col, int delrow[], int delcol[]) {
        
        // Base case: If already visited or not an 'O', return
        if (visited[row][col] || board[row][col] != 'O')
            return;

        // Mark the cell as visited
        visited[row][col] = 1;

        int m = board.size();
        int n = board[0].size();

        // Visit all 4 neighbors (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check for valid bounds before recursion
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                dfs(visited, board, nrow, ncol, delrow, delcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Visited matrix to keep track of 'O's connected to boundary
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Direction vectors for moving up, right, down, left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Step 1: Run DFS for all 'O's on the boundary (first & last row/column)

        // Left and Right boundary
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(visited, board, i, 0, delrow, delcol);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(visited, board, i, n - 1, delrow, delcol);
        }

        // Top and Bottom boundary
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(visited, board, 0, j, delrow, delcol);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(visited, board, m - 1, j, delrow, delcol);
        }

        // Step 2: Convert all remaining unvisited 'O's to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // These 'O's are surrounded by 'X' and not connected to boundary
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
