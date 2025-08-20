class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);        // parent[i] stores the ultimate parent of node i
        size.resize(n + 1, 1);       // size[i] stores the size of the component where i is the leader
        for (int i = 0; i <= n; i++) {
            parent[i] = i;           // initially, every node is its own parent (self component)
        }
    }

    // Function to find ultimate parent with path compression
    int findUPar(int node) {
        if (node == parent[node]) {  
            return node;             // if node is its own parent, return it
        }
        // path compression → directly link node to its ultimate parent
        return parent[node] = findUPar(parent[node]); 
    }

    // Function to unite two components by their size
    void unionBySize(int u, int v) {
        int pu = findUPar(u);        // ultimate parent of u
        int pv = findUPar(v);        // ultimate parent of v
        if (pu == pv)
            return;                  // already in the same component → nothing to do

        // attach smaller component under larger one
        if (size[pu] < size[pv]) {
            parent[pu] = pv;         // make pv the parent
            size[pv] += size[pu];    // increase size of pv’s component
        } else {
            parent[pv] = pu;         // make pu the parent
            size[pu] += size[pv];    // increase size of pu’s component
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();         // number of rows
        int m = grid[0].size();      // number of cols
        DisjointSet ds(n * m);       // total nodes = n*m, each cell treated as a node

        // ---------------- STEP 1: Build DSU for existing islands ----------------
        // connect all 1’s (land cells) with their 4-directional neighbors
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0)
                    continue;        // skip water cells (0), we only connect land (1)

                // directions: up, right, down, left
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                // check 4 neighbors
                for (int i = 0; i < 4; i++) {
                    int adjr = row + dr[i];    // neighbor row
                    int adjc = col + dc[i];    // neighbor col
                    if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m &&
                        grid[adjr][adjc] == 1) { // valid land neighbor
                        
                        // convert 2D cell (row, col) to 1D node number
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;

                        // union both land cells
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // ---------------- STEP 2: Try flipping each 0 to 1 ----------------
        int maxSize = INT_MIN;  // track maximum possible island size
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1)
                    continue;   // skip land → we only flip water cells

                // directions: up, right, down, left
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                // use set to avoid counting same component twice
                set<int> components;

                // check 4 neighbors of this 0
                for (int i = 0; i < 4; i++) {
                    int adjr = row + dr[i];
                    int adjc = col + dc[i];
                    if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m &&
                        grid[adjr][adjc] == 1) { // if neighbor is land
                        
                        // find parent of that neighbor
                        components.insert(ds.findUPar(adjr * n + adjc));
                    }
                }

                // sum up sizes of all unique neighboring components
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }

                // flipping this 0 adds +1 to size
                maxSize = max(maxSize, sizeTotal + 1);
            }
        }

        // ---------------- STEP 3: Handle case where grid is all 1 ----------------
        // If we never flipped any 0, maxSize stays INT_MIN
        // In that case, answer is entire grid (n*m)
        return maxSize == INT_MIN ? n * m : maxSize;
    }
};
