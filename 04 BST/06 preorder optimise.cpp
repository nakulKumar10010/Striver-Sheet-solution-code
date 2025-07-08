class Solution {
public:
    // ✅ Recursive helper function to build BST from preorder
    TreeNode* build(vector<int>& arr, int& i, int bound) {
        // Base case: end of array or current element > allowed bound
        if (i == arr.size() || arr[i] > bound)
            return NULL;

        // Create new node with current element
        TreeNode* root = new TreeNode(arr[i++]);

        // ✅ All elements < root->val go to left subtree
        root->left = build(arr, i, root->val);

        // ✅ All elements > root->val but < bound go to right subtree
        root->right = build(arr, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;

        // ✅ Start building with upper bound as INT_MAX (no limit)
        return build(preorder, i, INT_MAX);
    }
};

🧠 Intuition:
In a Binary Search Tree (BST):

Left child values < node

Right child values > node

In preorder traversal:

You visit Root → Left → Right

So, the first element is always the root

All following elements can be categorized as:

Belonging to the left subtree if they are smaller

Belonging to the right subtree if they are greater but within a certain bound

By maintaining a bound, we ensure elements are inserted only where they are valid in the BST.

📌 Approach:
Start from index 0 of the preorder array.

Use a recursive function:

Take the current element and create a node if it's ≤ bound.

Recursively build the left subtree with the current node's value as the new upper bound.

Recursively build the right subtree with the parent’s bound.

Automatically advances the index (i) through the preorder list without restarting each time.

🧾 Algorithm:
Define a recursive function build(arr, i, bound):

If i == arr.size() or arr[i] > bound: return NULL.

Create node root with arr[i++]

Build root->left with new bound root->val

Build root->right with existing bound

Initialize i = 0 and call build(preorder, i, INT_MAX)

Return the root of the constructed tree.

⏱️ Time and Space Complexity:
Time: O(n) — Every node is visited once.

Space: O(n) — Due to recursion stack (worst case in skewed BST).


