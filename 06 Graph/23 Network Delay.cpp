/*
Intuition:
----------
We have a directed weighted graph where each edge represents the time taken
for a signal to travel from one node to another. The signal starts at node k,
and we need to find the minimum time required for it to reach all nodes.
If any node is unreachable, return -1.
This is essentially a shortest path problem with positive weights, so
Dijkstra's Algorithm is ideal.

Approach:
---------
1. Build the adjacency list where each node stores its neighbors and the
   time taken to reach them.
2. Use a distance array initialized to infinity (INT_MAX) except for the
   starting node k, which is 0.
3. Use a min-heap (priority queue) to always pick the node with the smallest
   known distance so far.
4. For each node popped from the queue, relax its edges (update neighbor
   distances if a shorter path is found).
5. After processing, find the maximum distance in the dist[] array.
   - If any distance is still infinity, return -1 (unreachable node).
   - Else, return the maximum distance as the total network delay time.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list (1-indexed graph)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0]; // source node
            int v = times[i][1]; // destination node
            int w = times[i][2]; // travel time (weight)
            adj[u].push_back({v, w});
        }

        // Step 2: Initialize distance array with infinity
        vector<int> dist(n + 1, INT_MAX);

        // Step 3: Min-heap priority queue storing {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from source node k with distance 0
        pq.push({0, k});
        dist[k] = 0;

        // Step 4: Dijkstra's Algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;    // current distance
            int node = it.second; // current node

            // Explore all neighbors of the current node
            for (auto neigh : adj[node]) {
                int nextNode = neigh.first;
                int edgeWeight = neigh.second;

                // Relaxation: If shorter path found, update and push to PQ
                if (dist[nextNode] > edgeWeight + wt) {
                    dist[nextNode] = edgeWeight + wt;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // Step 5: Find maximum time to reach any node
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1; // Node unreachable
            maxi = max(maxi, dist[i]);
        }

        return maxi; // Total delay time
    }
};
