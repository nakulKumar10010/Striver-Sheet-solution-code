class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Queue stores pairs of (position index, node pointer)
        // Using unsigned long long to avoid overflow in deep trees
        queue<pair<unsigned long long, TreeNode*>> q;

        // Initialize the maximum width to 1 (since root exists)
        unsigned long long MaxWidth = 1;

        // Start with the root node at position 0
        q.push({0, root});

        while (!q.empty()) {
            int size = q.size();

            // Variables to track position of first and last node at the current level
            unsigned long long x1 = 0, x2 = 0;

            for (int i = 0; i < size; i++) {
                // Get position and node
                unsigned long long x = q.front().first;
                TreeNode* temp = q.front().second;
                q.pop();

                // Push left child with position 2 * x
                if (temp->left) {
                    q.push({2 * x, temp->left});
                }

                // Push right child with position 2 * x + 1
                if (temp->right) {
                    q.push({2 * x + 1, temp->right});
                }

                // Track the position of the first node at this level
                if (i == 0) {
                    x1 = x;
                }

                // Track the position of the last node at this level
                if (i == size - 1) {
                    x2 = x;
                }
            }

            // Update the maximum width
            MaxWidth = max(x2 - x1 + 1, MaxWidth);
        }

        // Return the maximum width found
        return MaxWidth;
    }
};
