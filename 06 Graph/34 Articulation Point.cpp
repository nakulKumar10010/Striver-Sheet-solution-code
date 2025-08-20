// User function Template for C++

class Solution {
  public:
    int timer = 0; // Global timer to assign discovery times to nodes

    /**
     * DFS function to identify articulation points.
     *
     * @param node   Current node being visited.
     * @param parent Parent of the current node in DFS tree.
     * @param vis    Keeps track of visited nodes.
     * @param tin    Discovery time of each node.
     * @param low    Lowest discovery time reachable from this node.
     * @param mark   Marks whether a node is an articulation point.
     * @param adj    Graph adjacency list.
     */
    void dfs(int node, int parent, vector<int>& vis,
             int tin[], int low[], vector<int> &mark, vector<int> adj[]) {

        vis[node] = 1;                // Mark current node as visited
        tin[node] = low[node] = timer; // Discovery and low time initialized
        timer++;                      // Increment global timer for next node

        int child = 0; // Counts number of DFS children of this node

        // Explore all neighbors of current node
        for (auto it : adj[node]) {
            if (it == parent)
                continue; // Skip edge back to parent

            if (vis[it] == 0) {
                // Tree Edge: visit unvisited neighbor
                dfs(it, node, vis, tin, low, mark, adj);

                // Update low value of current node after visiting child
                low[node] = min(low[node], low[it]);

                // Articulation Point Condition (for non-root nodes):
                // If the earliest reachable ancestor of child "it"
                // is discovered *after or at* node's discovery,
                // then removing "node" will disconnect the graph.
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++; // Count child for root articulation condition
            } else {
                // Back Edge: update low[node] with discovery time of visited node
                low[node] = min(low[node], tin[it]);
            }
        }

        // Special Case: Root node of DFS tree is articulation point
        // if it has more than one child.
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

    /**
     * Main function to find all articulation points in a graph.
     *
     * @param V   Number of vertices.
     * @param adj Graph adjacency list.
     * @return    List of articulation points, or {-1} if none exist.
     */
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);  // Track visited nodes
        int tin[V];             // Discovery times
        int low[V];             // Lowest discovery times reachable
        vector<int> mark(V, 0); // Marks articulation points (1 if true)

        // Run DFS for each component (important if graph is disconnected)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        // Collect all articulation points
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }

        // If no articulation point exists, return {-1}
        return ans.size() == 0 ? vector<int>{-1} : ans;
    }
};
