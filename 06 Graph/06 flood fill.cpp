class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc,
                                  int color) {
        int m = img.size();       // Get number of rows in the image
        int n = img[0].size();    // Get number of columns in the image

        vector<vector<int>> vis = img;  // Create a copy of the image to store the result

        queue<pair<int, int>> q;        // Queue for BFS traversal
        q.push({sr, sc});               // Start from the given pixel (sr, sc)
        vis[sr][sc] = color;            // Change the color of the starting pixel

        // Arrays to move in 4 directions: up, left, down, right
        int moveR[] = {-1, 0, 1, 0};
        int moveC[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;    // Current row
            int c = q.front().second;   // Current column
            q.pop();                    // Remove the current pixel from the queue

            // Traverse in all 4 directions
            for (int i = 0; i < 4; i++) {
                int newr = r + moveR[i];  // New row
                int newc = c + moveC[i];  // New column

                // Check if new coordinates are within bounds
                // and if the color matches the original starting pixel's color
                // and the pixel has not been colored yet
                if (newr >= 0 && newc >= 0 && newr < m && newc < n &&
                    vis[newr][newc] == img[sr][sc] &&
                    vis[newr][newc] != color) {

                    vis[newr][newc] = color;  // Color the new pixel
                    q.push({newr, newc});     // Push the new pixel to the queue for further processing
                }
            }
        }

        return vis;  // Return the modified image
    }
};
