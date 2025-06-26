class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);  // Vector to store next greater elements
        stack<int> st;       // Monotonic decreasing stack

        // Loop through the array twice in reverse to handle circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller than or equal to current element
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Only fill the answer for the first n elements
            if (i < n) {
                // If stack is empty, no greater element found, else top is the next greater
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push current element to stack for future comparisons
            st.push(nums[i % n]);
        }

        return nge;
    }
};
