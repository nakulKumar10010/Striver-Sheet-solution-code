class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        stack<int> st; // Stack to keep track of asteroids that are still in motion

        // Process each asteroid in the input array
        for (int i = 0; i < arr.size(); i++) {
            bool destroyed = false; // Flag to indicate if the current asteroid is destroyed

            // Check for collisions: top of stack is moving right (positive), current asteroid moving left (negative)
            while (!st.empty() && st.top() > 0 && arr[i] < 0) {
                if (abs(st.top()) < abs(arr[i])) {
                    // Stack asteroid is smaller → it explodes
                    st.pop();
                    // Continue checking with the next asteroid on stack
                    continue;
                } else if (abs(st.top()) == abs(arr[i])) {
                    // Both asteroids are the same size → both explode
                    st.pop();
                    destroyed = true; // Current asteroid also destroyed
                    break; // No more checks needed for current asteroid
                } else {
                    // Stack asteroid is larger → current asteroid explodes
                    destroyed = true;
                    break; // No more checks needed
                }
            }

            // If the current asteroid survived all collisions → push it onto the stack
            if (!destroyed) {
                st.push(arr[i]);
            }
        }

        // Build the result vector from the remaining asteroids in the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse because stack gives asteroids in reverse order of appearance
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
