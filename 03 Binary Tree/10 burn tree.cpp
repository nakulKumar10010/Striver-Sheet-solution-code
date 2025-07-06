class Solution {
  public:
    // Function to map each node to its parent in the tree
    void marksParents(Node* root,
                      unordered_map<Node*, Node*>& parent_track) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            // If left child exists, map it to its parent and add to queue
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            // If right child exists, map it to its parent and add to queue
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    // Function to find and return the node having the target value
    Node* getNode(Node* root, int target) {
        if (root == NULL) return NULL;  // Base case: empty subtree
        if (root->data == target) return root;  // Target found
        
        // Search in left subtree
        Node* left = getNode(root->left, target);
        if (left) return left;  // If found in left subtree, return
        
        // Else search in right subtree
        Node* right = getNode(root->right, target);
        return right;
    }
    
    // Function to compute minimum time to burn the entire tree starting from target node
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;  // Map to store parent of each node
        marksParents(root, parent_track);  // Populate the parent_track map

        unordered_map<Node*, bool> visited;  // To mark nodes that are already burned
        queue<Node*> queue;  // For BFS traversal
        
        Node* targetNode = getNode(root, target);  // Find the target node
        if (targetNode == NULL) return 0;  // If target not found, return 0
        
        queue.push(targetNode);  // Start BFS from target node
        visited[targetNode] = true;  // Mark target as visited (burned)
        
        int count = -1;  // Count represents time units (initially -1 because first level is 0)
        
        while (!queue.empty()) {
            int size = queue.size();  // Number of nodes burning at current time unit
            
            // Process all nodes at the current time unit
            for (int i = 0; i < size; i++) {
                Node* current = queue.front();
                queue.pop();
                
                // If left child exists and not burned yet, burn it
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                // If right child exists and not burned yet, burn it
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }

                // If parent exists and not burned yet, burn it
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            
            count++;  // Increment time after each level
        }

        return count;  // Return total time taken to burn the tree
    }
};
