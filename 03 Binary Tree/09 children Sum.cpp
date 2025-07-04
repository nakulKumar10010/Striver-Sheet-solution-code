class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // If the tree is empty, it satisfies the sum property
        if (root == NULL) {
            return 1;
        }

        // Use a queue for level-order traversal (BFS)
        queue<Node*> q;
        q.push(root);

        // Loop until all nodes are processed
        while (!q.empty()) {
            int size = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                int leftValue = 0, rightValue = 0;

                // If left child exists, add it to the queue and store its value
                if (temp->left != NULL) {
                    q.push(temp->left);
                    leftValue = temp->left->data;
                }

                // If right child exists, add it to the queue and store its value
                if (temp->right != NULL) {
                    q.push(temp->right);
                    rightValue = temp->right->data;
                }

                // If the node is not a leaf node, check sum property
                if (temp->left != NULL || temp->right != NULL) {
                    // Node's data must be equal to the sum of its children's data
                    if (temp->data != leftValue + rightValue) {
                        return 0; // Property violated
                    }
                }
            }
        }

        // If all nodes satisfy the sum property, return 1
        return 1;
    }
};
