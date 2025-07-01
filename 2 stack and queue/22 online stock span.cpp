class StockSpanner {
public:
    // Stack to store pairs of (price, index)
    // Each pair represents a price and the day (index) it occurred
    stack<pair<int, int>> st;

    // Keeps track of the current day index
    int ind = -1;

    // Constructor — nothing to initialize explicitly here
    StockSpanner() {}

    int next(int price) {
        // Move to the next day
        ind++;

        // Pop all prices from the stack that are <= current price
        // Why? Because these prices are not greater than current price,
        // so they cannot affect the span of future prices either
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // If the stack is empty, it means current price is the highest so far,
        // so the span is (current index + 1) = ind - (-1)
        // Otherwise, span = distance to last greater price = ind - st.top().second
        int ans = ind - (st.empty() ? -1 : st.top().second);

        // Push the current price and its index onto the stack
        // This will serve as a reference for future spans
        st.push({price, ind});

        // Return the computed span
        return ans;
    }
};
