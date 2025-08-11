// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Build adjacency list from edge list
        // adj[u] contains pairs {v, weight} representing an edge u -> v of given weight
        vector<vector<pair<int, int>>> adj(V);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove this line if the graph is directed
        }

        // Step 2: Distance array initialized to infinity
        // dist[i] = shortest distance from src to node i
        vector<int> dist(V, INT_MAX);
        
        // Step 3: Set will store {distance, node}
        // The set acts as a min-priority queue for selecting the next closest unvisited node
        set<pair<int, int>> st;
        
        // Step 4: Initialize source node distance to 0 and insert into set
        dist[src] = 0;
        st.insert({0, src});
        
        // Step 5: Main Dijkstra loop — process until all reachable nodes are finalized
        while (!st.empty()) {
            // Extract the node with the smallest distance (greedy choice)
            auto startingValue = *(st.begin());
            int node = startingValue.second;
            int dis = startingValue.first;
            st.erase(startingValue); // remove it from the set (mark as processed)
            
            // Step 6: Relaxation step — check all neighbors of current node
            for (auto &it : adj[node]) {
                int edgeWt = it.second; // weight of edge from node -> adjNode
                int adjNode = it.first; // neighboring node
                
                // If a shorter path to adjNode is found, update it
                if (edgeWt + dis < dist[adjNode]) {
                    
                    // Remove old record from set if present
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    // Update distance and insert new pair into set
                    dist[adjNode] = edgeWt + dis;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        // Step 7: Return the shortest distance array
        return dist;
    }
};
