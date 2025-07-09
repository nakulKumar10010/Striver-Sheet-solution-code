// Function to find the predecessor and successor of a given key in a BST
vector<Node*> findPreSuc(Node* root, int key) {
    vector<Node*> ans(2, NULL); // ans[0] = predecessor, ans[1] = successor

    Node* cur = root;

    // 🔍 Find predecessor (largest node less than key)
    while (cur != NULL) {
        if (cur->data < key) {
            ans[0] = cur;         // Store current as potential predecessor
            cur = cur->right;     // Try to find a larger value still less than key
        } else {
            cur = cur->left;      // Move left to find smaller value
        }
    }

    cur = root;

    // 🔍 Find successor (smallest node greater than key)
    while (cur != NULL) {
        if (cur->data > key) {
            ans[1] = cur;         // Store current as potential successor
            cur = cur->left;      // Try to find a smaller value still greater than key
        } else {
            cur = cur->right;     // Move right to find larger value
        }
    }

    return ans; // Return vector with predecessor and successor nodes
}

🏫 Institution
Data Structure: Binary Search Tree (BST)

Problem: Find the predecessor and successor of a given key in a BST.

🧠 Algorithmic Approach
🔹 Concept
In a BST:

Left subtree contains values less than root.

Right subtree contains values greater than root.

The predecessor of a given key is the largest value less than the key.
The successor is the smallest value greater than the key.

🔹 Approach
Initialize a result array ans[2] to store predecessor (ans[0]) and successor (ans[1]).

Traverse the tree to find the predecessor:

If root->data < key, current node can be a predecessor, move right to find closer value.

Else move left.

Reset the root and repeat similar logic for successor:

If root->data > key, current node can be a successor, move left to find closer value.

Else move right.

🔹 Time Complexity
O(h) where h is the height of the BST.

For balanced BST: O(log n)

For skewed BST: O(n)

🔹 Space Complexity
O(1) (no extra space used apart from result array)
