class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; // Stack to keep track of next greater elements
        unordered_map<int, int> nge; // Map to store next greater element for each number in nums2

        int n = nums2.size();
        
        // Traverse nums2 from right to left to build the next greater map
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack until we find a greater element
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            // If stack is empty, there is no greater element to the right
            if (st.empty())
                nge[nums2[i]] = -1;
            else
                nge[nums2[i]] = st.top(); // Top of stack is the next greater element

            // Push current element to stack for future comparisons
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Build the answer for nums1 using the precomputed map
        for (auto val : nums1) {
            ans.push_back(nge[val]); // Get the next greater element from map
        }

        return ans;
    }
};
