not optimised
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // ✅ First node in preorder is always the root of the BST
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curr = root;
        int i = 1;

        while (i < preorder.size()) {
            // ✅ If current node value > next preorder value → go left
            if (curr->val > preorder[i]) {
                if (curr->left) {
                    // Keep moving left if left child exists
                    curr = curr->left;
                } else {
                    // Create new left child
                    TreeNode* node = new TreeNode(preorder[i]);
                    curr->left = node;
                    i++;         // move to next element
                    curr = root; // restart from root
                }
            } else {
                // ✅ If current node value < next preorder value → go right
                if (curr->right) {
                    // Keep moving right if right child exists
                    curr = curr->right;
                } else {
                    // Create new right child
                    TreeNode* node = new TreeNode(preorder[i]);
                    curr->right = node;
                    i++;         // move to next element
                    curr = root; // restart from root
                }
            }
        }

        return root;
    }
};


🧠 Intuition:
In a Binary Search Tree (BST):

The left child is always less than the parent.

The right child is always greater than the parent.

In preorder traversal, we visit:
Root → Left → Right

So the first element is always the root, and all following elements must be placed into the BST while respecting BST properties.

📌 Approach:
Start with the first element as the root.

For every next element:

Compare it with the current node.

Go left if it's smaller.

Go right if it's larger.

When you find an empty position, insert the node.

Restart from root for the next element.

🧾 Algorithm:
Create root from preorder[0].

Loop through the remaining elements:

Initialize curr as root.

Traverse left or right based on BST property.

Insert node when empty spot is found.

Reset curr to root for the next insertion.

Repeat until all nodes are inserted.

Return root
