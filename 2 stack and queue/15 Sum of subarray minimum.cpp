class Solution {
public:
    const int MOD = 1e9 + 7; // To handle large numbers and avoid overflow

    // Function to find the index of the Next Smaller Element for each element
    vector<int> findNse(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n); // Stores index of the next smaller element

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are not smaller than current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on right -> use n
            // Otherwise, top of the stack is the next smaller element
            nse[i] = st.empty() ? n : st.top();

            // Push current index onto stack
            st.push(i);
        }

        return nse;
    }

    // Function to find the index of the Previous Smaller Element for each element
    vector<int> findPsee(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> psee(n); // Stores index of the previous smaller element

        for (int i = 0; i < n; i++) {
            // Pop elements from the stack that are greater than current element
            // We do not use >= here to ensure strict "previous smaller" condition
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on left -> use -1
            // Otherwise, top of the stack is the previous smaller element
            psee[i] = st.empty() ? -1 : st.top();

            // Push current index onto stack
            st.push(i);
        }

        return psee;
    }

    // Function to calculate the sum of minimums of all subarrays
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n), psee(n);

        // Get indices of next and previous smaller elements
        nse = findNse(arr);
        psee = findPsee(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            // Count of subarrays where arr[i] is the minimum
            int left = i - psee[i];      // number of elements to the left including current
            int right = nse[i] - i;      // number of elements to the right including current

            // Contribution of arr[i] to the total sum
            total = (total + (1LL * left * right * arr[i]) % MOD) % MOD;
        }

        return total;
    }
};
