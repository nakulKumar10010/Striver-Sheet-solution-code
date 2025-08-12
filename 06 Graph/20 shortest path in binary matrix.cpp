/*
Intuition:
----------
We need to find the shortest path from the top-left cell (0,0) to the bottom-right cell (n-1,n-1)
in a binary matrix where 0 = free cell and 1 = blocked cell. Movement is allowed in all 8 directions
(up, down, left, right, and diagonals). Since all moves have equal cost (1 step), Breadth-First Search (BFS)
is the ideal choice — it explores all cells level by level and guarantees the shortest distance.

Approach:
---------
1. If the starting or ending cell is blocked, return -1 immediately (no path possible).
2. Use a BFS queue to store {distance_so_far, {row, col}} for each reachable cell.
3. Keep a 'dist' matrix to track the shortest distance to each cell; initialize with INT_MAX.
4. Start BFS from (0,0) with distance = 1 (counting the starting cell as a step).
5. From each cell, try moving in all 8 directions.
6. For each valid and unblocked neighbor cell, update the distance if a shorter path is found and push it into the queue.
7. At the end, check the distance to the bottom-right cell:
   - If still INT_MAX, it means no path was found, return -1.
   - Otherwise, return the stored distance as the shortest path length.
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // (1) If start or end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // (2) dist[r][c] stores shortest distance to reach (r,c)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // (3) BFS queue: {distance_so_far, {row, col}}
        queue<pair<int, pair<int, int>>> q;

        // (4) Start BFS from (0,0) with distance = 1 (count starting cell)
        q.push({1, {0, 0}});
        dist[0][0] = 1;

        // (5) All 8 possible directions (vertical, horizontal, diagonal)
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // (6) Standard BFS loop
        while (!q.empty()) {
            int r = q.front().second.first;   // current row
            int c = q.front().second.second;  // current col
            int d = q.front().first;          // distance so far
            q.pop();

            // (7) Try all 8 moves from current cell
            for (int i = 0; i < 8; i++) {
                int newr = r + delRow[i];
                int newc = c + delCol[i];

                // (8) Valid cell check: inside grid, unblocked, shorter path found
                if ((newr >= 0 && newr < n) && (newc < n && newc >= 0) &&
                    (grid[newr][newc] == 0) && (dist[newr][newc] > d + 1)) {
                    
                    // (9) Update shortest distance & push to BFS queue
                    dist[newr][newc] = d + 1;
                    q.push({d + 1, {newr, newc}});
                }
            }
        }

        // (10) If end cell was never reached, return -1
        return (dist[n - 1][n - 1] == INT_MAX) ? -1 : dist[n - 1][n - 1];
    }
};
