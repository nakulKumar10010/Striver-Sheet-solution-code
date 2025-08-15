/*
-------------------- Intuition --------------------
Kruskal’s Algorithm is used to find the Minimum Spanning Tree (MST) of a 
connected, undirected, and weighted graph. 
The main idea is:
1. Sort all edges in increasing order of their weights.
2. Pick the smallest edge that does not form a cycle with the already 
   included edges in the MST.
3. Use Disjoint Set Union (DSU) / Union-Find data structure to efficiently 
   check if adding an edge forms a cycle.
4. Stop when we have (V - 1) edges in the MST.

We use:
- Path Compression in "find" → speeds up repeated parent lookups.
- Union by Size → always attach smaller tree to larger tree to keep DSU shallow.

-------------------- Approach --------------------
1. Create a Disjoint Set (DSU) for V vertices.
2. Sort all edges by weight (ascending).
3. Iterate over edges:
   - If the current edge connects two different sets (no cycle), 
     include it in MST and union the sets.
4. Return the sum of the included edge weights.
*/

class DisjointSet {
    vector<int> parent, size; // parent array & size array for Union by Size
public:
    DisjointSet(int n) {
        parent.resize(n + 1);  // initialize parent array (0 to n)
        size.resize(n + 1, 1); // initial size of each component is 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // each node is its own parent initially
        }
    }
    
    // Finds the ultimate parent of a node (with path compression)
    int findUPar(int node) {
        if (node == parent[node]) {
            return node; // ultimate parent found
        }
        // Path compression: directly connect node to ultimate parent
        return parent[node] = findUPar(parent[node]);
    }
    
    // Union by Size: attach smaller tree under larger tree
    void UnionBySize(int u, int v) {
        int pu = findUPar(u); // ultimate parent of u
        int pv = findUPar(v); // ultimate parent of v
        if (pu == pv) return; // already in the same set → cycle
        
        if (size[pu] < size[pv]) { 
            parent[pu] = pv;         // attach u's tree under v's tree
            size[pv] += size[pu];    // update size of v's tree
        } else {
            parent[pv] = pu;         // attach v's tree under u's tree
            size[pu] += size[pv];    // update size of u's tree
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DisjointSet ds(V); // initialize DSU for V vertices
        
        // Step 1: Sort edges by weight
        sort(edges.begin(), edges.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2]; // compare weights
             });
        
        int mstWt = 0; // total weight of MST
        
        // Step 2: Iterate through sorted edges
        for (auto &it : edges) {
            int u = it[0]; // vertex 1
            int v = it[1]; // vertex 2
            int wt = it[2]; // weight of edge
            
            // Step 3: If u and v are in different components → no cycle
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;          // add weight to MST sum
                ds.UnionBySize(u, v); // union the components
            }
        }
        
        // Step 4: Return total MST weight
        return mstWt;
    }
};
