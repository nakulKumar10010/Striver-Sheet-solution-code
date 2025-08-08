//DFS - but bad approach
class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int node, vector<int> &path, int cost){
        if(path[node] != -1 && cost >= path[node]){
            return;
        }
        path[node] = cost;
        
        
        for(auto it : adj[node]){
            dfs(adj, it, path, cost+1);
        }
    }
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int v = adj.size();
        vector<int> path(v, -1);
        
        //start with source
        dfs(adj, src, path, 0);
        
        return path;
        
    }
};



class Solution {
public:
    // Function to find the shortest path from source to all other nodes in an unweighted graph
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v = adj.size();                  // Number of vertices in the graph
        vector<int> dist(v, -1);              // Distance array, initialized to -1 (meaning unreachable)

        queue<int> q;                         // Queue for BFS traversal
        q.push(src);                          // Start BFS from source node
        dist[src] = 0;                        // Distance to source is 0

        while (!q.empty()) {
            int node = q.front();             // Get current node
            q.pop();

            // Visit all neighbors of the current node
            for (auto it : adj[node]) {
                // If neighbor not visited yet OR we found a shorter distance
                if (dist[it] == -1 || dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1; // Update distance
                    q.push(it);                // Push neighbor into queue for further exploration
                }
            }
        }

        return dist; // Returns distances from src to all nodes (-1 means unreachable)
    }
};
