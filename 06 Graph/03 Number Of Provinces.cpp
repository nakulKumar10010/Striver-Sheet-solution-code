// Helper function to perform DFS traversal
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node) {
    visited[node] = 1; // Mark the current node (city) as visited

    int n = isConnected.size(); // Total number of cities

    // Traverse all other cities to find direct connections
    for (int i = 0; i < n; i++) {
        // If city 'i' is directly connected to 'node' and not yet visited
        if (isConnected[node][i] && !visited[i]) {
            dfs(isConnected, visited, i); // Recursively visit the connected city
        }
    }
}

// Main function to count the number of provinces
int findCircleNum(vector<vector<int>>& isConnected) {
    int v = isConnected.size(); // Number of cities

    vector<int> visited(v, 0); // Visited array to keep track of visited cities
    int noOfProvinces = 0; // Counter for number of connected components (provinces)

    // Iterate through each city
    for (int i = 0; i < v; i++) {
        // If the current city hasn't been visited yet
        if (!visited[i]) {
            noOfProvinces++; // A new province is found
            dfs(isConnected, visited, i); // Explore all cities in this province
        }
    }

    return noOfProvinces; // Return the total number of provinces
}
