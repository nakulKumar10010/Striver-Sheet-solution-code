class DisjointSet {
public:
    vector<int> parent, size;

    // Constructor to initialize DSU
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // initially, each component has size 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // every node is its own parent initially
        }
    }

    // Find ultimate parent with path compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node; // node is its own parent
        }
        // path compression: directly connect node to ultimate parent
        return parent[node] = findUPar(parent[node]); 
    }

    // Union by size: attach smaller tree under bigger tree
    void UnionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return; // already in same set

        if (size[pu] < size[pv]) {
            parent[pu] = pv;        // attach pu's root to pv's root
            size[pv] += size[pu];   // increase size of pv's component
        } else {
            parent[pv] = pu;        
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        // Step 1: Find max row and max col index to size DSU properly
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Step 2: Create DSU with enough space for (rowNodes + colNodes)
        // Trick: Row nodes = 0..maxRow, Col nodes = maxRow+1 .. maxRow+maxCol+1
        DisjointSet ds(maxRow + maxCol + 1);

        // Keep track of which nodes (row/col) are actually used by stones
        unordered_map<int, int> stoneNodes;

        // Step 3: Union row index with col index for each stone
        for (auto it : stones) {
            int nodeRow = it[0]; 
            int nodeCol = it[1] + maxRow + 1; // shift col index to avoid clash with rows

            ds.UnionBySize(nodeRow, nodeCol);

            // mark these nodes as active (present in graph)
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // Step 4: Count number of connected components
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++; // root found = one connected component
            }
        }

        // Step 5: Max stones removable = total stones - number of components
        // Because in each component, at least 1 stone must remain
        return n - cnt;
    }
};
