// Helper DFS function to explore a connected component
    void dfs(vector<int> adj[], vector<int>& visited, int node, vector<int>& ls) {
        visited[node] = 1;      // Mark current node as visited
        ls.push_back(node);     // Add current node to the current component list
        
        // Visit all unvisited neighbors
        for(auto it : adj[node]){
            if (!visited[it]) {
                dfs(adj, visited, it, ls); // Recursive DFS call
            }
        }
    }

    // Main function to find all connected components
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> adj[V]; // Adjacency list

        // Step 1: Build the adjacency list from the given edge list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // Add v to u's list
            adj[v].push_back(u); // Add u to v's list (undirected graph)
        }

        vector<vector<int>> ans;       // To store all connected components
        vector<int> visited(V, 0);     // Visited array to track visited nodes

        // Step 2: Run DFS from every unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> ls;        // List to store current component
                dfs(adj, visited, i, ls); // Perform DFS to collect the component
                ans.push_back(ls);     // Add current component to result
            }
        }

        return ans; // Return all connected components
    }
//NKR
