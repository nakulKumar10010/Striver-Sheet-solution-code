/*
Intuition:
----------
We need to find the sum of the weights of the Minimum Spanning Tree (MST) of a graph.
Prim’s algorithm grows the MST starting from any node, 
always picking the smallest weight edge that connects a visited node to an unvisited node.
We use a min-heap (priority_queue with greater<>) to efficiently get the smallest edge.

Approach:
---------
1. Convert the edge list into an adjacency list for efficient traversal.
2. Use a min-heap to store pairs of {weight, node}, always popping the smallest weight first.
3. Start from node 0 with weight 0.
4. While the heap is not empty:
   - Pop the smallest edge.
   - If the node is not visited:
       a) Mark it visited.
       b) Add its edge weight to the total sum.
       c) Push all its unvisited neighbors into the min-heap.
5. Repeat until all nodes are included in the MST.
6. Return the total sum of MST edge weights.
*/

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list from given edges
        vector<pair<int, int>> adj[V]; // {neighbor, weight}
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int sum = 0; // Stores total MST weight
        vector<int> visited(V, 0); // Track visited nodes

        // Step 2: Min-heap (priority queue) to store {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Step 3: Start from node 0 with weight 0
        pq.push({0, 0});

        // Step 4: Process until heap is empty
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;   // Current edge weight
            int node = it.second; // Current node

            // Step 5: If node is not visited, include it in MST
            if (!visited[node]) {
                visited[node] = 1; // Mark as visited
                sum += wt;         // Add edge weight to MST sum

                // Step 6: Push all unvisited neighbors into min-heap
                for (auto neigh : adj[node]) {
                    int adjNode = neigh.first;
                    int edgeWeight = neigh.second;
                    if (!visited[adjNode]) {
                        pq.push({edgeWeight, adjNode});
                    }
                }
            }
        }

        // Step 7: Return total weight of MST
        return sum;
    }
};
