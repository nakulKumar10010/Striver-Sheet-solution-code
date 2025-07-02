int solve(TreeNode* root, int& diameter) {
    // Base case: if the node is null, height is 0
    if (root == NULL) {
        return 0;
    }

    // Recursively find the height of the left subtree
    int lh = solve(root->left, diameter);
    
    // Recursively find the height of the right subtree
    int rh = solve(root->right, diameter);
    
    // Update the diameter if the path through the current node is larger
    // (path = left height + right height)
    diameter = max(diameter, lh + rh);

    // Return height of the current node = 1 + max height of its subtrees
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    // Initialize diameter as 0
    int diameter = 0;

    // Compute height of tree while updating diameter
    solve(root, diameter);

    // Return the final computed diameter
    return diameter;
}
