// Function to check if the current color assignment is valid
bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& graph) {
for (int neighbor : graph[node]) {
    // If the adjacent node has the same color, it's not safe
    if (colors[neighbor] == color)
        return false;
}
return true;
}

// Recursive function to try coloring each node
bool solve(int node, int V, int m, vector<int>& colors, vector<vector<int>>& graph) {
// Base case: If all vertices are colored
if (node == V)
    return true;

// Try all colors from 1 to m
for (int c = 1; c <= m; c++) {
    // Check if it's safe to color this node with color c
    if (isSafe(node, c, colors, graph)) {
        colors[node] = c; // Assign color c to node

        // Recur to color the next node
        if (solve(node + 1, V, m, colors, graph))
            return true;

        // Backtrack: undo the color assignment
        colors[node] = 0;
    }
}

// If no color can be assigned to this node, return false
return false;
}

// Main function to check m-colorability
bool graphColoring(int V, vector<vector<int>>& edges, int m) {
// Create the adjacency list
vector<vector<int>> graph(V);
for (auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    graph[u].push_back(v);
    graph[v].push_back(u); // Because the graph is undirected
}

// Initialize color array (0 means no color assigned yet)
vector<int> colors(V, 0);

// Start coloring from node 0
return solve(0, V, m, colors, graph);
}
