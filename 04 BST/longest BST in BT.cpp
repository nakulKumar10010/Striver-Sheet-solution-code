// Helper class to store information about a subtree:
// - minNode: minimum value in the subtree
// - maxNode: maximum value in the subtree
// - maxSize: size of the largest BST in the subtree
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    // Constructor to initialize the NodeValue object
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    // Helper function that returns NodeValue for each subtree
    NodeValue largestBSTSubtreeHelper(Node* root) {
        // Base case: if the node is NULL, return a default valid BST state
        // INT_MAX as min, INT_MIN as max ensures that any parent node can form a BST with this
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // Recursively compute values from left and right subtrees
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // If current node satisfies BST properties with left and right subtrees
        // i.e., max value in left subtree < current node value < min value in right subtree
        if (left.maxNode < root->data && root->data < right.minNode) {
            // Current tree is a BST
            // Compute min and max values for current subtree
            int newMin = min(root->data, left.minNode);
            int newMax = max(root->data, right.maxNode);
            int newSize = left.maxSize + right.maxSize + 1;

            // Return updated values for this subtree
            return NodeValue(newMin, newMax, newSize);
        }

        // If not a BST, return invalid min/max to prevent ancestors from treating it as a BST
        // maxSize is still the maximum of left or right valid BST sizes
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    // Main function that returns the size of the largest BST subtree
    int largestBst(Node* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};


🔍 Explanation
Why INT_MAX and INT_MIN?

Used to represent edge values so the parent can still validate BST property when a subtree is empty (NULL).

When returning INT_MIN, INT_MAX in error case, we ensure ancestors do not treat the subtree as valid BST.

Why return NodeValue(INT_MIN, INT_MAX, max(...)) in the failure case?

This indicates the current subtree is not a BST.

But we still want to track the largest valid BST subtree found in the left or right subtree.

Why use post-order traversal?

You need to first evaluate left and right children before determining if the current root can be part of a valid BST.

That’s why recursive post-order is used.
