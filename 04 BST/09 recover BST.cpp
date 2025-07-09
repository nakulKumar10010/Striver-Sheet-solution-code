// Definition of the Solution class
class Solution {
public:
    // Pointers to track the nodes that are misplaced
    TreeNode* first;   // Pointer to the first node that is out of place
    TreeNode* prev;    // Pointer to keep track of the previously visited node in inorder traversal
    TreeNode* middle;  // Pointer to the middle node (used in case the swapped nodes are adjacent)
    TreeNode* last;    // Pointer to the last node that is out of place (used in case the swapped nodes are not adjacent)

    // Helper function to perform inorder traversal of the BST
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        // Recurse on the left subtree
        inorder(root->left);

        // Check for violations of BST property (current node should be greater than previous node)
        if (prev != NULL && (root->val < prev->val)) {
            // If this is the first violation, mark 'first' and 'middle'
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            // If this is the second violation, mark 'last'
            else {
                last = root;
            }
        }

        // Update 'prev' to current node before moving to the right subtree
        prev = root;

        // Recurse on the right subtree
        inorder(root->right);
    }

    // Function to recover the BST by correcting the swapped nodes
    void recoverTree(TreeNode* root) {
        // Initialize all pointers to NULL
        first = middle = last = NULL;

        // Initialize 'prev' with a dummy node having the smallest possible value
        // This helps in comparing with the first node in the inorder traversal
        prev = new TreeNode(INT_MIN);

        // Perform inorder traversal and find the two nodes that were swapped
        inorder(root);

        // If two non-adjacent nodes were swapped, we would have 'first' and 'last' marked
        if (first && last)
            swap(first->val, last->val); // Correct the swap

        // If two adjacent nodes were swapped, we would have 'first' and 'middle' marked
        else if (first && middle)
            swap(first->val, middle->val); // Correct the swap
    }
};
