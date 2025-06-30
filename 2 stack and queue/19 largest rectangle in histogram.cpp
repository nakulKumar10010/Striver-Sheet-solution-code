// method 1
class Solution {
public:
    // Function to find the index of the next smaller element for each element
    vector<int> nextsmallerelement(vector<int>& heights, int n) {
        stack<int> s;
        s.push(-1); // Sentinel value for no smaller element
        vector<int> arr(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            // Pop elements from stack until we find a smaller one
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            arr[i] = s.top(); // Index of the next smaller element
            s.push(i); // Push current index
        }
        return arr;
    }

    // Function to find the index of the previous smaller element for each element
    vector<int> prevsmallerelement(vector<int>& heights, int n) {
        stack<int> s;
        s.push(-1); // Sentinel value for no smaller element
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            // Pop elements from stack until we find a smaller one
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            arr[i] = s.top(); // Index of the previous smaller element
            s.push(i); // Push current index
        }
        return arr;
    }

    // Function to compute the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Compute next and previous smaller elements for each bar
        vector<int> next = nextsmallerelement(heights, n);
        vector<int> prev = prevsmallerelement(heights, n);

        int area = INT_MIN;

        // Compute area for each bar as the smallest bar in a rectangle
        for (int i = 0; i < n; i++) {
            int length = heights[i]; // height of the rectangle

            // If there is no smaller element to the right, assume end of histogram
            if (next[i] == -1) {
                next[i] = n;
            }

            // Calculate width of rectangle using next and previous smaller indices
            int breadth = next[i] - prev[i] - 1;

            // Calculate area and update maximum
            int newArea = length * breadth;
            area = max(area, newArea);
        }

        return area;
    }
};

//method 2 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;          // Stack to store indices of histogram bars
        int maxArea = 0;        // Variable to keep track of max area found
        int n = heights.size(); // Total number of bars

        for (int i = 0; i < n; i++) {
            // If current bar is smaller than the bar at stack top,
            // pop and calculate area of rectangle with the popped bar as the smallest bar
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()]; // Height of the bar
                st.pop();                        // Remove it as we're done with it

                int nse = i;                     // Current index is next smaller element
                int pse = st.empty() ? -1 : st.top(); // Top of stack after pop is previous smaller
                maxArea = max(maxArea, element * (nse - pse - 1)); // Update max area
            }
            st.push(i); // Push current index onto stack
        }

        // Process remaining bars in stack (no smaller bar to the right)
        while (!st.empty()) {
            int element = heights[st.top()]; // Height of the bar
            st.pop();

            int nse = n;                     // Right boundary is end of histogram
            int pse = st.empty() ? -1 : st.top(); // Previous smaller element
            maxArea = max(maxArea, element * (nse - pse - 1)); // Update max area
        }

        return maxArea; // Return the largest rectangle area found
    }
};

/*
Stack keeps track of indices of increasing bars.

When current bar is smaller → calculate area for taller bars.

After loop → clean up remaining bars assuming right boundary at n.

Formula: height * (nse - pse - 1). */
