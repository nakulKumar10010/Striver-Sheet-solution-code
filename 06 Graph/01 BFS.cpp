vector<int> bfs(vector<vector<int>> &adj) {
    int v = adj.size(); // Get the number of vertices in the graph based on the size of adjacency list

    vector<int> BFS; // This will store the final BFS traversal order
    vector<int> visited(v, 0); // To keep track of visited nodes, initialized with 0 (unvisited)
    queue<int> q; // Queue to perform BFS traversal

    // As given, start traversal from node 0
    q.push(0); // Push the starting node (0) into the queue
    visited[0] = 1; // Mark node 0 as visited

    // Continue until the queue becomes empty
    while(!q.empty()){
        int node = q.front(); // Get the front node from the queue
        BFS.push_back(node); // Add the current node to the BFS traversal result
        q.pop(); // Remove the front node from the queue

        // Traverse all the adjacent (neighbouring) nodes of the current node
        for(auto it : adj[node]){
            if(!visited[it]){ // If the neighbour hasn't been visited yet
                q.push(it); // Push it into the queue for further traversal
                visited[it] = 1; // Mark the neighbour as visited
            }
        }
    }

    return BFS; // Return the final BFS traversal order
}
