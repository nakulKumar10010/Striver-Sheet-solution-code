class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();         // Number of rows
        int m = grid[0].size();      // Number of columns

        // Queue stores {{row, col}, time}, for BFS traversal
        queue<pair<pair<int, int>, int>> q;

        // Visited array to mark rotten oranges and avoid reprocessing
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0; // Count of fresh oranges

        // Step 1: Traverse the grid to initialize the queue with all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Push rotten orange position and time = 0
                    vis[i][j] = 2;       // Mark as visited (rotten)
                }
                if (grid[i][j] == 1)
                    cntFresh++;         // Count fresh oranges
            }
        }

        // Directions: up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        int tm = 0; // Maximum time taken to rot all reachable fresh oranges

        // Step 2: Multi-source BFS from all initially rotten oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);  // Update time taken
            q.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Valid cell, unvisited, and has a fresh orange
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    
                    q.push({{nrow, ncol}, t + 1}); // Enqueue with incremented time
                    vis[nrow][ncol] = 2;           // Mark as rotten
                    cntFresh--;                    // One less fresh orange
                }
            }
        }

        // Step 3: If any fresh orange remains, return -1
        if (cntFresh != 0)
            return -1;

        return tm; // Total time to rot all oranges
    }
};
