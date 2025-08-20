class Solution {
  public:
    // DFS function for the original graph (Step 1)
    // This function explores the graph and pushes nodes into stack
    // according to their finishing time (postorder).
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
        vis[node] = 1;  // mark the current node as visited
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);  // recursive DFS call
            }
        }
        // Once all neighbors are processed, push this node into stack.
        // This ensures that the node with the latest finishing time is on top.
        st.push(node);
    }
    
    // DFS function for the transposed graph (Step 3)
    // Used to explore one complete SCC at a time.
    void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // Step 1: Sort nodes by finishing times using DFS
        int v = adj.size();         // number of vertices
        vector<int> vis(v, 0);      // visited array
        stack<int> st;              // stack to store finishing order

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        // Step 2: Reverse the graph (transpose graph)
        // If there is an edge u -> v in original graph,
        // then in transposed graph it becomes v -> u.
        vector<int> adjT[v];  // adjacency list for transposed graph
        for (int i = 0; i < v; i++) {
            vis[i] = 0;  // reset visited array for second DFS
            for (auto it : adj[i]) {
                adjT[it].push_back(i);  // reverse the edge
            }
        }
        
        // Step 3: Do DFS in the order defined by the stack
        // Every DFS call in this step will give one SCC.
        int scc = 0;  
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!vis[node]) {
                dfs3(node, vis, adjT);  // explore full SCC
                scc++;  // increment SCC count
            }
        }
        
        return scc;  // total number of strongly connected components
    }
};
