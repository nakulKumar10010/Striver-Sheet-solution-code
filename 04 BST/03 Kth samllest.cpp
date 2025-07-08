class Solution {
public:
    // Helper function to perform inorder traversal and find the k-th smallest element
    void solve(TreeNode* root, int& k, int& element) {
        // Traverse the left subtree first (inorder traversal)
        if (root->left)
            solve(root->left, k, element);

        // Decrement k since we're visiting one more node
        k--;

        // If k becomes 0, we've found the k-th smallest element
        if (k == 0) {
            element = root->val;
            return; // Stop further traversal
        }

        // Traverse the right subtree
        if (root->right)
            solve(root->right, k, element);
    }

    // Main function to find the k-th smallest element in the BST
    int kthSmallest(TreeNode* root, int k) {
        int element; // Variable to store the result
        solve(root, k, element); // Start inorder traversal
        return element; // Return the k-th smallest element
    }
};

NOTE - Inorder traversal of BST is always sorted
