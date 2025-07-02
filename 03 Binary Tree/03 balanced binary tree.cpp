int solve(TreeNode* root) {
    // Base case: if the node is NULL, height is 0
    if (root == NULL)
        return 0;

    // Recursively find the height of left subtree
    int lh = solve(root->left);

    // Recursively find the height of right subtree
    int rh = solve(root->right);

    // If any subtree is unbalanced, propagate -1 upwards
    if (lh == -1 || rh == -1)
        return -1;

    // If the difference in heights is greater than 1, it's unbalanced
    if (abs(lh - rh) > 1)
        return -1;

    // Return the height of the current subtree
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    // If solve returns -1, tree is unbalanced
    if (solve(root) == -1)
        return false;

    // Otherwise, tree is balanced
    return true;
}
