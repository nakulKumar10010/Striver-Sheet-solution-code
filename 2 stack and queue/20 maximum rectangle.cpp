class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        // Traverse through all bars of the histogram
        for (int i = 0; i < n; i++) {
            // Maintain stack in increasing order of heights
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()];
                st.pop();

                // Right boundary (NSE: next smaller element)
                int nse = i;
                // Left boundary (PSE: previous smaller element)
                int pse = st.empty() ? -1 : st.top();

                // Calculate area using height * width
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }

        // Process remaining elements in the stack
        while (!st.empty()) {
            int element = heights[st.top()];
            st.pop();

            int nse = n;  // No smaller element on right
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Prefix sum matrix to store histogram heights
        vector<vector<int>> pSum(n, vector<int>(m));

        // Build histogram: column-wise accumulation of '1's
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (matrix[i][j] - '0'); // Convert char to int
                if (matrix[i][j] == '0')
                    sum = 0;  // Reset sum if 0 is encountered
                pSum[i][j] = sum;  // Store height at (i,j)
            }
        }

        int maxAr = 0;

        // For each row (as histogram), compute largest rectangle area
        for (int i = 0; i < n; i++) {
            maxAr = max(maxAr, largestRectangleArea(pSum[i]));
        }

        return maxAr;
    }
};
/*Summary of key concepts in comments

largestRectangleArea → Monotonic stack to compute largest rectangle in histogram.

pSum matrix → Builds histogram row-by-row using column prefix sums.

maximalRectangle → Treat each row as histogram and apply largest rectangle logic.*/
