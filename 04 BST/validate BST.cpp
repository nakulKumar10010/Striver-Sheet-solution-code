class Solution {
public:
    // Helper function to validate the BST
    // Each node must lie strictly between mini and maxi
    bool solve(TreeNode* root, long long mini, long long maxi) {
        // Base case: empty tree is a valid BST
        if (root == NULL)
            return true;

        // If current node's value violates the min/max constraint, it's not a BST
        if (root->val <= mini || root->val >= maxi)
            return false;

        // Recursively validate left and right subtrees:
        // Left child must be < root->val
        // Right child must be > root->val
        return solve(root->left, mini, root->val) &&
               solve(root->right, root->val, maxi);
    }

    // Main function to check if a binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Use long long min/max to safely handle edge integer values
        return solve(root, LONG_MIN, LONG_MAX);
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

  🔁 Summary for Quick Revision:
Idea: A valid BST must follow the rule: left < root < right recursively.

Use bounds (mini, maxi) to ensure each node is within valid range.

Why long long? To avoid overflow issues with values like INT_MIN, INT_MAX.
