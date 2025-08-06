class Solution {
  public:
    // Helper function to perform DFS and push nodes to stack in post-order
    void detect(vector<int> &visited, vector<int> adj[], stack<int> &st, int node){
        visited[node] = 1; // Mark current node as visited
        
        // Visit all unvisited adjacent nodes
        for(auto it : adj[node]){
            if(!visited[it]){
                detect(visited, adj, st, it);
            }
        }

        // After all adjacent nodes are visited, push current node to stack
        st.push(node);
    }

    // Function to perform topological sort
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0); // Track visited nodes
        
        vector<int> adj[V]; // Adjacency list representation of graph

        // Build the adjacency list from edge list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // Directed edge from u to v
        }

        stack<int> st; // Stack to store topological order

        // Perform DFS for all unvisited nodes
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                detect(visited, adj, st, i);
            }
        }

        // Extract topological order from stack
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
