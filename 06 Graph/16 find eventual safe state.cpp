class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        // Stores the number of outgoing edges for each node (in original graph)
        vector<int> indegree(v, 0);

        // Reversed graph: for each edge u -> v in original, add v -> u in adjRev
        vector<vector<int>> adjRev(v);

        // Step 1: Build the reverse graph and compute outdegrees (indegree[] in reverse)
        for (int i = 0; i < v; i++) {
            for (int v_adj : graph[i]) {
                adjRev[v_adj].push_back(i); // Reverse edge
                indegree[i]++;              // i has an outgoing edge
            }
        }

        // Step 2: Initialize queue with terminal nodes (nodes with 0 outgoing edges)
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i); // Safe to start with terminal nodes
            }
        }

        vector<int> safeNode; // Stores all eventually safe nodes

        // Step 3: Perform BFS (Kahn’s algorithm on reversed graph)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNode.push_back(node); // Node is safe

            // Visit all nodes pointing to this node in reversed graph
            for (auto it : adjRev[node]) {
                indegree[it]--; // Reduce outdegree of that node
                if (indegree[it] == 0) {
                    q.push(it); // If it becomes terminal, mark it as safe
                }
            }
        }

        // Step 4: Sort result to return in increasing order as required
        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
