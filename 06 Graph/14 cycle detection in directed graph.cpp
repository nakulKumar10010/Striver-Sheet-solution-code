class Solution {
  public:
    // DFS function to detect cycle in directed graph using visited and path arrays
    bool dfs(vector<int> adj[], vector<int> &visited, vector<int> &path, int node) {
        visited[node] = 1;     // Mark current node as visited
        path[node] = 1;        // Mark current node in current DFS path

        for (auto it : adj[node]) {
            if (!visited[it]) {
                // If the adjacent node is not visited, do DFS recursively
                if (dfs(adj, visited, path, it)) {
                    return true; // If cycle is detected in DFS subtree
                }
            } 
            else if (path[it]) {
                // If the adjacent node is already in the current path, cycle detected
                return true;
            }
        }

        path[node] = 0; // Backtrack: remove node from current DFS path
        return false;   // No cycle found from this node
    }

    // Main function to check cycle in directed graph
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];

        // Build adjacency list from edge list (u -> v, directed graph)
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v); // Directed edge from u to v
        }

        vector<int> visited(V, 0); // Tracks visited nodes
        vector<int> path(V, 0);    // Tracks nodes in current DFS path

        // Check every node (for disconnected components)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, path, i)) {
                    return true; // If cycle found in any component
                }
            }
        }

        return false; // No cycle detected in any component
    }
};
