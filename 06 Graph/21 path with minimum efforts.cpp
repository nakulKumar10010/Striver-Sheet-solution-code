/*
Intuition:
We need to reach the bottom-right cell from the top-left cell with the smallest possible "effort".
Effort of a path = maximum absolute difference in heights between two consecutive cells on that path.
This is similar to Dijkstra’s shortest path, but instead of summing distances, we take the maximum.

Approach:
1. Use a min-heap (priority queue) to always explore the path with the smallest current effort first.
2. Keep a dist matrix where dist[r][c] = minimum effort to reach (r, c).
3. For each neighbor, calculate the effort as max(current_effort, height_difference).
4. If this effort is smaller than the stored effort, update and push to the queue.
5. Stop early when we reach bottom-right — that effort is guaranteed to be minimal.
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();        // Number of rows
        int m = heights[0].size();     // Number of columns

        // dist[r][c] stores the minimum effort required to reach cell (r, c)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Min-heap: stores {effort_so_far, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // Start from top-left cell with effort 0
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // 4 possible movements: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;         // Current path effort
            int r = it.second.first;     // Current row
            int c = it.second.second;    // Current column

            // If we've reached the destination, return the effort
            if (r == n - 1 && c == m - 1)
                return diff;

            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newr = r + delRow[i];
                int newc = c + delCol[i];

                // Check if neighbor is inside the grid
                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    // Effort to move to this neighbor
                    int newEffort = max(abs(heights[newr][newc] - heights[r][c]), diff);

                    // If we found a smaller effort path, update and push to heap
                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }

        return 0; // This line should never be reached
    }
};
