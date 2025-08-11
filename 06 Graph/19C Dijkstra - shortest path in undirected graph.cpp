class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list for the graph
        // Each entry: adj[node] = list of {adjacent_node, edge_weight}
        vector<pair<int, int>> adj[n + 1];
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]}); // Undirected graph: add both directions
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Step 2: Initialize distance array and parent array
        // dist[i] = shortest distance from node 1 to node i
        // parent[i] = previous node in the shortest path to i
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i; // Initially, parent is itself

        // Step 3: Min-heap (priority queue) for Dijkstra
        // Stores {distance, node} with smallest distance on top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 4: Start from node 1 (distance = 0)
        dist[1] = 0;
        pq.push({0, 1});

        // Step 5: Process the priority queue
        while (!pq.empty()) {
            auto [dis, node] = pq.top(); // Current shortest distance and node
            pq.pop();

            // Step 6: Explore neighbors of the current node
            for (auto &[adjNode, edW] : adj[node]) {
                // If shorter path found, update distance and parent
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        // Step 7: If destination 'n' is unreachable
        if (dist[n] == (int)1e9) return {-1};

        // Step 8: Reconstruct the shortest path from node 1 to n
        vector<int> path;
        int node = n;
        while (parent[node] != node) { // Until reaching the start node
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // Add the starting node

        // Step 9: Reverse to get path from start to destination
        reverse(path.begin(), path.end());

        // Step 10: Return the path
        return path;
    }
};
