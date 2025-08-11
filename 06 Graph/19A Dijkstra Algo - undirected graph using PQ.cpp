// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Create adjacency list for weighted graph
        // adj[i] -> vector of {neighbor, weight} pairs for vertex i
        vector<vector<pair<int, int>>> adj(V);
        
        // Build adjacency list from edges
        // Each edge: [u, v, wt]
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});    // edge u -> v with weight wt
            adj[v].push_back({u, wt});    // edge v -> u with weight wt (undirected)
        }

        // Step 2: Distance array, initialized to infinity
        vector<int> dist(V, INT_MAX);
        
        // Step 3: Min-heap priority queue -> stores {distance, node}
        // The smallest distance node will be processed first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Step 4: Initialize source node
        dist[src] = 0;               // distance to source = 0
        pq.push({0, src});           // push source into min-heap
        
        // Step 5: Main loop until all reachable nodes are processed
        while(!pq.empty()){
            int dis = pq.top().first;    // current shortest distance
            int node = pq.top().second;  // current node
            pq.pop();
            
            // Optional optimization to skip outdated entries
            // This prevents processing a node if we have already found a shorter path
            // if (dis > dist[node]) continue;
            
            // Step 6: Relaxation of edges
            // Check all adjacent nodes of the current node
            for(auto &it : adj[node]){
                int edgeWt = it.second;   // weight of edge node -> adjNode
                int adjNode = it.first;   // neighbor node
                
                // If shorter path is found, update and push into queue
                if(edgeWt + dis < dist[adjNode]){
                    dist[adjNode] = edgeWt + dis;
                    pq.push({edgeWt + dis, adjNode});
                }
            }
        }
        
        // Step 7: Return final shortest distances from source to all nodes
        return dist;
    }
};
