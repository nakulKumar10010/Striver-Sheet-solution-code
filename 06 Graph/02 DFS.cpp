// Helper function to perform DFS recursively
void dfsTraversal(vector<vector<int>>& adj, vector<int>& visited, vector<int>& DFS, int node){
    visited[node] = 1; // Mark the current node as visited
    DFS.push_back(node); // Add the current node to the DFS result list

    // Traverse all adjacent nodes (neighbors) of the current node
    for(auto it: adj[node]){
        if(!visited[it]){ // If the neighbor hasn't been visited yet
            dfsTraversal(adj, visited, DFS, it); // Recursively perform DFS on the neighbor
        }
    }
    return; // Return after exploring all reachable nodes from the current node
}

// Main function to initiate DFS traversal
vector<int> dfs(vector<vector<int>>& adj) {
    int v = adj.size(); // Get the number of vertices from the adjacency list

    vector<int> visited(v, 0); // Visited array to keep track of visited nodes, initialized to 0 (unvisited)
    vector<int> DFS; // Vector to store the final DFS traversal order

    dfsTraversal(adj, visited, DFS, 0); // Start DFS from node 0 (as per problem assumption)

    return DFS; // Return the DFS traversal order
}
