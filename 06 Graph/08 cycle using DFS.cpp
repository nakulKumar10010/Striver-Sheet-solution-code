class Solution {
  public:
    // DFS for cycle detection in an undirected graph
    bool detect(vector<int> &visited, vector<int> adj[], int parent, int node){
        visited[node] = 1;  // Mark current node as visited
        
        for(auto it : adj[node]){  // Traverse all adjacent nodes
            if(!visited[it]){  // If the adjacent node is not visited
                if(detect(visited, adj, node, it)) return true;  // Recursively visit the node
            }
            else if(it != parent){  // If visited and not parent => cycle detected
                return true;
            }
        }
        
        return false;  // No cycle found in this path
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0);  // To track visited nodes
        
        vector<int> adj[V];  // Adjacency list representation
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph => add both u->v and v->u
        }
        
        // Check all components (handles disconnected graph too)
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(detect(visited, adj, -1, i))  // Call DFS from unvisited node
                    return true;  // Cycle found
            }
        }
        
        return false;  // No cycle found in any component
    }
};
