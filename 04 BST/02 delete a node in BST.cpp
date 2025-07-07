class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL; // Base case: tree is empty

        TreeNode* cur = root;  // Pointer to traverse the tree
        TreeNode* prev = NULL; // Pointer to keep track of the parent

        // Traverse the tree to find the node to delete
        while (cur != NULL) {
            if (cur->val == key) {
                TreeNode* temp = cur;             // Node to be deleted
                TreeNode* rightChild = cur->right; // Save the right child

                if (rightChild == NULL) {
                    // ✅ Case 1: No right child (only left child or no child)
                    if (prev == NULL) {
                        // Node to delete is root
                        root = cur->left;
                    } else if (prev->left == temp) {
                        // Node is left child of parent
                        prev->left = cur->left;
                    } else {
                        // Node is right child of parent
                        prev->right = cur->left;
                    }
                } else {
                    // ✅ Case 2: Has right child (may or may not have left)
                    if (prev == NULL) {
                        // Node to delete is root
                        root = rightChild;
                    } else if (prev->left == temp) {
                        // Node is left child of parent
                        prev->left = rightChild;
                    } else {
                        // Node is right child of parent
                        prev->right = rightChild;
                    }

                    // Attach the left subtree to the leftmost node of right subtree
                    TreeNode* leftmost = rightChild;
                    while (leftmost->left != NULL) {
                        leftmost = leftmost->left;
                    }

                    leftmost->left = temp->left;
                }

                delete temp; // Free the memory of the deleted node
                break;       // Node deleted, exit loop
            } else if (cur->val < key) {
                // Move right if key is greater
                prev = cur;
                cur = cur->right;
            } else {
                // Move left if key is smaller
                prev = cur;
                cur = cur->left;
            }
        }

        return root; // Return the possibly updated root
    }
};

--------------------------------------------------------------NOTE------------------------------------------------------------------------------------

Key Concepts:
  
This solution handles two main deletion cases:

No right child: Replace node with left child.

Has right child: Replace node with right child, and attach left subtree to the leftmost node in the right subtree.

The traversal is iterative and tracks the parent (prev) for reconnection.

Let me know if you’d like a recursive version or explanation with diagrams.








