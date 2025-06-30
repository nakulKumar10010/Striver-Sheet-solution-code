class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // Iterate over each digit in the input number
        for (int i = 0; i < num.size(); i++) {
            // Remove digits from the stack if:
            // 1. The stack is not empty
            // 2. We still have digits to remove (k > 0)
            // 3. The current stack top is greater than the current digit (to make number smaller)
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            // Push the current digit to the stack
            st.push(num[i]);
        }

        // If we still have k digits left to remove, pop from the end (larger digits at the end)
        while (k) {
            st.pop();
            k--;
        }

        // Build the result string from the stack (digits are in reverse order)
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Reverse the string to get the correct order
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;
        result = result.substr(i);

        // If the result is empty (all digits removed or all were zeros), return "0"
        return result.empty() ? "0" : result;
    }
};
