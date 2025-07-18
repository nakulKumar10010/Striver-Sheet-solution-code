class Solution {
  public:
    // Function to perform BFS for cycle detection
    bool detect(vector<int> &visited, vector<int> adj[], int src){
        queue<pair<int,int>> q; // Queue stores pairs of (node, parent)
        visited[src] = 1; // Mark source node as visited
        q.push({src, -1}); // Start BFS from source with parent as -1
        
        while(!q.empty()){
            int node = q.front().first;   // Current node
            int parent = q.front().second; // Parent of current node
            q.pop();
            
            for(auto it : adj[node]){
                // If adjacent node is not visited
                if(! visited[it]){
                    visited[it] = 1;        // Mark as visited
                    q.push({it, node});     // Push it into the queue with current node as its parent
                }
                // If adjacent node is visited and not the parent of current node,
                // then a cycle is detected
                else if(it != parent){
                    return true;
                }
            }
        }
        
        return false; // No cycle found in this component
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Initialize visited array to keep track of visited nodes
        vector<int> visited(V, 0);
        
        // Convert edge list to adjacency list
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // Add edge u-v
            adj[v].push_back(u); // Add edge v-u (since the graph is undirected)
        }
        
        // Traverse all components of the graph
        for(int i = 0; i < V; i++){
            // If node is not visited, check for cycle from that node
            if(! visited[i]){
                if(detect(visited, adj, i))
                    return true; // Cycle detected
            }
        }
        
        return false; // No cycle in any component
    }
};
