class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();             // Number of rows
        int n = mat[0].size();          // Number of columns

        // visited keeps track of visited cells during BFS
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // dist stores the distance of each cell to the nearest 0
        vector<vector<int>> dist(m, vector<int>(n, 0));

        // queue for BFS: stores ((row, col), distance)
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Push all 0s in the queue as BFS starting points
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;         // Mark as visited
                    q.push({{i, j}, 0});       // Push coordinates with distance 0
                }
            }
        }

        // Directions for movement: up, right, down, left
        int moveR[] = {-1, 0, 1, 0};
        int moveC[] = {0, 1, 0, -1};

        // Step 2: Perform BFS from all 0s simultaneously
        while (!q.empty()) {
            // Extract front node from queue
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            // Store current distance in result matrix
            dist[r][c] = d;

            // Explore 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newr = r + moveR[i];
                int newc = c + moveC[i];

                // Check if neighbor is inside grid and unvisited
                if (newr >= 0 && newc >= 0 && newr < m && newc < n &&
                    !visited[newr][newc]) {

                    visited[newr][newc] = 1;          // Mark neighbor as visited
                    q.push({{newr, newc}, d + 1});     // Push neighbor with updated distance
                }
            }
        }

        // Return the matrix containing distances to nearest 0
        return dist;
    }
};
