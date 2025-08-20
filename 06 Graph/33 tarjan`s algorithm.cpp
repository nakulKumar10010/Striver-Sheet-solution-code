class Solution {
public:
    int timer = 1; // A global timer used to assign discovery times to nodes

    /**
     * DFS function to explore the graph and find bridges.
     * 
     * @param node   Current node being visited.
     * @param parent Parent of the current node in DFS tree.
     * @param vis    Keeps track of visited nodes.
     * @param adj    Adjacency list representation of the graph.
     * @param tin    Array to store discovery time (when a node was first visited).
     * @param low    Array to store the lowest discovery time reachable from this node.
     * @param bridges Stores the critical connections (bridges).
     */
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[],
             int tin[], int low[], vector<vector<int>>& bridges) {

        vis[node] = 1;               // Mark current node as visited
        tin[node] = low[node] = timer; // Initially, discovery time = low time = timer
        timer++;                     // Increment timer for the next node

        // Explore all neighbors of the current node
        for (auto it : adj[node]) {
            if (it == parent) 
                continue; // Skip the edge leading back to parent (avoid going in circles)

            if (vis[it] == 0) {
                // If neighbor is not visited, perform DFS on it
                dfs(it, node, vis, adj, tin, low, bridges);

                // After returning, update the low value of current node
                low[node] = min(low[node], low[it]);

                // Bridge condition: if the earliest reachable node from 'it'
                // is discovered after 'node', then (node-it) is a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node}); // Store the bridge edge
                }
            } else {
                // If neighbor already visited and not parent,
                // this is a back edge, update low[node]
                low[node] = min(low[node], low[it]);
            }
        }
    }

    /**
     * Main function to find all critical connections (bridges) in the graph.
     * 
     * @param n            Number of nodes in the graph.
     * @param connections  List of edges in the graph.
     * @return             List of bridges (critical connections).
     */
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        // Step 1: Build adjacency list (since graph is undirected, add both ways)
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Step 2: Initialize helper structures
        vector<int> vis(n, 0); // To mark visited nodes
        int tin[n];            // Discovery time of each node
        int low[n];            // Lowest discovery time reachable from this node
        vector<vector<int>> bridges; // To store the final answer

        // Step 3: Call DFS starting from node 0
        // (⚠️ Note: if the graph is disconnected, we should loop over all nodes)
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};
