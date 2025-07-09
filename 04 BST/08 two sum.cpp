approach - 2 
/**
 * BSTIterator:
 * This iterator class allows us to traverse the BST either in normal in-order (ascending)
 * or reverse in-order (descending) based on the `isReverse` flag.
 */
class BSTIterator {
    stack<TreeNode*> myStack;  // Stack to simulate the traversal
    bool reverse = true;       // Flag to control direction: true = reverse in-order

public:
    // Constructor initializes the stack with the path to the smallest or largest node
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // Check if there are more elements in the iterator
    bool hasNext() { 
        return !myStack.empty(); 
    }

    // Return the next element in the iteration
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();

        // Based on traversal direction, push the appropriate subtree
        if (!reverse)
            pushAll(tempNode->right);  // For in-order, explore right subtree
        else
            pushAll(tempNode->left);   // For reverse in-order, explore left subtree

        return tempNode->val;
    }

private:
    // Helper function to push all nodes along the path to the extreme (left or right)
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            // In reverse mode, go as right as possible
            // In normal mode, go as left as possible
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

/**
 * Solution class:
 * Uses two BSTIterators (one from smallest, one from largest) to simulate
 * the two-pointer approach on a sorted array to find two values that sum up to k.
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        // Left iterator: in-order (ascending)
        BSTIterator l(root, false);
        // Right iterator: reverse in-order (descending)
        BSTIterator r(root, true);

        // Start with smallest and largest elements
        int i = l.next();
        int j = r.next();

        // Two-pointer approach to find if two elements sum to k
        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();  // Move forward to increase sum
            else
                j = r.next();  // Move backward to decrease sum
        }

        // No such pair found
        return false;
    }
};

Summary of Key Concepts:
The BSTIterator class is a smart in-order/reverse-in-order iterator using a stack.

The findTarget method performs a two-pointer approach on BST by traversing from both ends.

Time Complexity: ~O(N) in the worst case, but often much better (average ~O(log N) space and time per call to next()).

Space Complexity: O(H) where H is the height of the BST (stack space).
