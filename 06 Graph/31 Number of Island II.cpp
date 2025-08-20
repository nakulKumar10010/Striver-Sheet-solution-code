// User function Template for C++
class DisjointSet {
public:
    // `parent` vector stores the parent of each node. `parent[i] = i` means i is a root.
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            // Each node is initially its own parent, representing a separate set/island.
            parent[i] = i;
        }
    }

    // findUPar (Find Ultimate Parent): Finds the representative of the set to which a node belongs.
    // This function also performs path compression, which flattens the tree structure
    // by making every node on the path point directly to the root. This significantly
    // optimizes subsequent `findUPar` calls.
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // path compression
    }

    // unionBySize: Merges two sets based on their size.
    // This is a crucial optimization that keeps the tree depth minimal, preventing a skewed
    // structure and ensuring near-constant time complexity for operations.
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            // If both nodes already have the same ultimate parent, they are in the same set,
            // so no union is needed.
            return;
        if (size[pu] < size[pv]) {
            // Attach the smaller tree (pu's) to the larger tree (pv's).
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            // Attach the smaller tree (pv's) to the larger or equal tree (pu's).
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // The Disjoint Set will manage n * m nodes, one for each cell in the grid.
        DisjointSet ds(n * m);
        
        // A 2D visited grid to keep track of which cells have become land.
        // It's used to avoid processing the same cell multiple times.
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // `cnt` stores the current number of islands. It's a running count.
        int cnt = 0;
        
        // `ans` will store the number of islands after each operation.
        vector<int> ans;
        
        // Iterate through each operation provided in the `operators` vector.
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            // Tricky part: If the current cell is already land, no new island is formed,
            // and no existing islands can merge. We just push the current island count
            // and move on to the next operation.
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            // Step 1: Mark the cell as land.
            vis[row][col] = 1;
            
            // Step 2: Initially assume this new piece of land creates a new, separate island.
            // This is a clever approach: we increment the count first, and then correct it
            // if we find it merges with an existing island.
            cnt++;
            
            // Step 3: Check the four cardinal neighbors (up, right, down, left).
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                
                // Check if the neighbor is within grid bounds AND is already land.
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && vis[adjr][adjc] == 1){
                    // Convert the 2D coordinates (row, col) to a single 1D index
                    // for use with the Disjoint Set data structure.
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    
                    // Crucial logic: Check if the new cell and its adjacent land cell
                    // belong to different islands.
                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                        // If they are from different islands, a union operation will merge them.
                        // Since two islands become one, the total island count decreases by one.
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            // After checking all neighbors, the final island count for this operation is pushed.
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
