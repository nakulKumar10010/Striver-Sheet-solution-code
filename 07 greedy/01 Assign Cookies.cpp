class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g -> greed factor of children (minimum cookie size needed by each child)
        // s -> size of cookies available

        // Step 1: Sort both arrays
        // - Sorting helps us use the smallest available cookie for the least greedy child.
        // - Greedy approach: always satisfy the child with the smallest requirement first.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // pointer for children (tracks how many children are satisfied)
        int j = 0; // pointer for cookies (tracks which cookie we are trying to use)

        // Step 2: Assign cookies one by one
        // We iterate until either:
        // - all children are checked (i == g.size()), or
        // - all cookies are used (j == s.size()).
        while (i < g.size() && j < s.size()) {
            
            // Case 1: If the current cookie can satisfy the current child
            // g[i] <= s[j] means the cookie size is enough for child i's greed
            if (g[i] <= s[j]) {
                // Assign cookie j to child i
                i++; // move to next child (child is satisfied)
            }
            
            // Case 2: Whether child was satisfied or not, move to the next cookie
            // Because:
            // - If the cookie was big enough, it's already used.
            // - If it was too small, it can't satisfy any other child either
            //   (since children are sorted in increasing greed).
            j++;
        }

        // Step 3: Return number of satisfied children
        // i represents how many children were satisfied before we ran out of cookies
        return i;
    }
};
