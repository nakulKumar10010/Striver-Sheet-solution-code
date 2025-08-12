class Solution {
public:
    /*
    Intuition:
    We are finding the cheapest price from src to dst within at most K stops.
    This is like a shortest path problem but with an extra constraint: 
    we can take at most K+1 edges (K stops). 
    Dijkstra’s algorithm doesn’t directly work because it greedily finalizes the shortest path 
    to a node without considering that a slightly more expensive path might use fewer stops 
    and lead to a cheaper final path later.

    Approach:
    - Represent the flights as an adjacency list where each edge has a cost.
    - Use BFS-like traversal (level = stops) starting from src.
    - Maintain dist[] to store the minimum cost to reach each node.
    - For each node, explore its neighbors only if we have stops left.
    - Update dist[] if a cheaper cost is found and push into the queue with stops - 1.

    Why not priority queue (Dijkstra)?
    - Dijkstra finalizes the shortest path once found, but here a cheaper final route 
      may come from a path that initially costs more but uses fewer stops.
    - We need to allow revisiting nodes with different remaining stops.
    - BFS layered by stops ensures we explore all valid paths up to K stops.
    */

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        // Build adjacency list from flights
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX); // Stores minimum cost to reach each node
        queue<pair<int, pair<int, int>>> q; // {remaining stops, {current cost, current node}}

        // Start from src with cost 0 and k stops allowed
        q.push({k, {0, src}});
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front().second.second; // Current node
            int stop = q.front().first;         // Remaining stops
            int wt = q.front().second.first;    // Current total cost
            q.pop();

            if (stop < 0)
                continue; // No more stops allowed

            // Explore all neighbors
            for (auto &it : adj[node]) {
                // If we can reach neighbor cheaper, update and push to queue
                if (dist[it.first] > wt + it.second) {
                    dist[it.first] = wt + it.second;
                    q.push({stop - 1, {dist[it.first], it.first}});
                }
            }
        }

        // If destination not reachable, return -1
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
