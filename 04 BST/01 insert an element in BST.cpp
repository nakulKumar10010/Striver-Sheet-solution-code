class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: if the tree is empty, insert the new value as the root node
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* cur = root;  // Start traversing from the root

        while (true) {
            // If the value to insert is greater than or equal to the current node's value
            if (cur->val <= val) {
                // Move to the right child if it exists
                if (cur->right != NULL)
                    cur = cur->right;
                else {
                    // If right child is NULL, insert the new value here
                    cur->right = new TreeNode(val);
                    break;
                }
            } else { // If the value to insert is less than the current node's value
                // Move to the left child if it exists
                if (cur->left != NULL)
                    cur = cur->left;
                else {
                    // If left child is NULL, insert the new value here
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }

        // Return the original root as the tree's structure is modified in-place
        return root;
    }
};
