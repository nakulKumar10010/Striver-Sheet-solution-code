class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;  // Vector to store the right side view nodes
        
        if (root == NULL)
            return ans;  // If the tree is empty, return empty result
        
        queue<TreeNode*> q;  // Queue for level order traversal (BFS)
        q.push(root);  // Start with the root node
        
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level
            
            // The first node in the queue at each level (since we push right first) 
            // will be the rightmost node of that level
            ans.push_back(q.front()->val);
            
            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                // Push right child first so it appears earlier in the queue
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                
                // Then push left child
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
            }
        }
        return ans;  // Return the list of right side view nodes
    }
};
