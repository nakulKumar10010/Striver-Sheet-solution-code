// User function Template for C++
class Solution {
public:
    // DFS-based Topological Sort
    // node -> current vertex
    // adj  -> adjacency list (with weights)
    // vis  -> visited array
    // st   -> stack to store topo order
    void topoSort(int node, vector<pair<int, int>> adj[],
                  vector<int> &vis, stack<int> &st) {
        vis[node] = 1; // mark as visited
        for (auto it : adj[node]) {
            int v = it.first; // destination node
            if (!vis[v]) {
                topoSort(v, adj, vis, st); // DFS call
            }
        }
        st.push(node); // push after visiting all children (post-order)
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // ---------------------
        // Step 0: Build adjacency list (with weights)
        // adj[u] -> list of {v, weight}
        // ---------------------
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {  // loop over all edges
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // ---------------------
        // Step 1: Topological sort of DAG
        // ---------------------
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // ---------------------
        // Step 2: Initialize distance array
        // INT_MAX = infinity
        // dist[0] = 0 (assuming source = 0)
        // ---------------------
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        // ---------------------
        // Step 3: Relax edges in topological order
        // ---------------------
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // If node has been reached before
            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    // Relaxation: if shorter path found, update it
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // ---------------------
        // Step 4: Mark unreachable nodes as -1
        // ---------------------
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
