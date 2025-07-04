class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        // Map to store the first node's data at each horizontal distance (x)
        map<int, int> mp;
        
        // Queue for level order traversal; stores pair of (horizontal distance, node pointer)
        queue<pair<int, Node*>> q;
        
        // Start BFS with root at horizontal distance 0
        q.push({0, root});
        
        while (!q.empty()) {
            int x = q.front().first;      // Current node's horizontal distance
            Node* temp = q.front().second; // Current node pointer
            q.pop();
            
            // If this horizontal distance is seen for the first time, record it
            if (mp.find(x) == mp.end()) {
                mp[x] = temp->data;
            }
            
            // Add left child with horizontal distance x - 1
            if (temp->left) {
                q.push({x - 1, temp->left});
            }
            
            // Add right child with horizontal distance x + 1
            if (temp->right) {
                q.push({x + 1, temp->right});
            }
        }
        
        // Collect the top view nodes in order from leftmost to rightmost
        for (auto p : mp) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
