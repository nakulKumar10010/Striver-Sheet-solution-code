class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // Deque to store *indices* of elements in nums. It helps to efficiently maintain candidates for max in window.
        int n = nums.size();
        vector<int> ans;  // To store the result: max of each sliding window.

        for (int i = 0; i <= n - 1; i++) {

            // Remove indices from front if they are out of the current window's range.
            // i - k represents the index that just moved out of the window.
            // We check if dq.front() <= i - k, if so, that index is outdated and should be removed.
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain elements in deque in decreasing order of their values in nums[].
            // Remove elements from back of deque if the current element nums[i] is greater
            // because they can't be max in this window or any future window including nums[i].
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current element's index to the deque.
            dq.push_back(i);

            // Once the first k elements are processed (i >= k - 1), 
            // the element at the front of the deque is the maximum of the current window.
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

/*
✅ dq.front() <= i - k

This ensures we remove indices that are no longer part of the sliding window.

i - k gives the index just outside the current window, so dq.front() ≤ i - k means that index has slid out and should be discarded.

✅ nums[dq.back()] <= nums[i] loop

If current nums[i] is greater than or equal to elements at deque's back, they can't be max in this window or any future window where nums[i] exists.

Removing them ensures deque stores potential max candidates only.

✅ dq.front() gives max

The deque is maintained in decreasing order of nums[], so dq.front() is always the max in the current window.
*/
