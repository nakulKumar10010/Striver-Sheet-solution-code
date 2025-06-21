//METHOD -1 using pair SC-O(2N) TC-O(1)
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }

        if (val > st.top().second) {
            st.push({val, st.top().second});
        } else {
            st.push({val, val});
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        st.pop();
        return;
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

//METHOD -2 trick type
class MinStack {
private:
    stack<long long> st; // Stack to store values (some encoded)
    long long mini;           // Stores the current minimum value

public:
    // Constructor initializes the minimum
    MinStack() { mini = INT_MAX; }

    // Pushes an element onto the stack
    void push(int val) {
        long long value = val;

        if (st.empty()) {
            // First element, set it as minimum and push directly
            mini = value;
            st.push(value);
        } else {
            if (value < mini) {
                // Push encoded value and update minimum
                st.push(2LL * value - mini);
                mini = value;
            } else {
                // Push value normally
                st.push(value);
            }
        }
    }

    // Removes the top element from the stack
    void pop() {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        // If top was an encoded value, restore previous minimum
        if (topVal < mini) {
            mini = 2LL * mini - topVal;
        }
    }

    // Returns the top element of the stack
    int top() {
        if (st.empty())
            return -1;

        long long topVal = st.top();

        // If encoded, return current minimum
        if (topVal < mini)
            return mini;

        return topVal;
    }

    // Returns the current minimum element in the stack
    int getMin() { return mini; }
};
