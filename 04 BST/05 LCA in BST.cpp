class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        int curr = root->val;

        // ✅ Case 1: If both p and q are greater than root,
        // LCA lies in right subtree.
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // ✅ Case 2: If both p and q are smaller than root,
        // LCA lies in left subtree.
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // ✅ Case 3: One node lies on left and one on right (divergence point)
        // OR one of them is equal to root => root is the LCA.
        return root;
    }
};
-----------------------------------------------------------------------------------------------------------------------------------------------------------
  🧠 Intuition:
In a Binary Search Tree (BST), for any node:
 Left subtree contains nodes with values smaller than the node.
 Right subtree contains nodes with values greater than the node.

So, to find the **Lowest Common Ancestor (LCA):
 If both nodes lie on the same side (left/right), move that way.
The moment the nodes split (one left, one right), or one matches the current node → we've found the LCA.

---
📌 Approach:

* Start from the root.
* Use BST properties to move left/right.
* Keep traversing until a split occurs or one node is found.

---
 🧾 Algorithm:

1. Start at root.
2. Compare root's value with `p` and `q`:
   * If root < p and root < q → go right.
   * If root > p and root > q → go left.
   * Else, root is the LCA.
3. Return the root when divergence or match is found.

---
