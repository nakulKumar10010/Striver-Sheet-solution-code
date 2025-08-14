/*
Intuition:
----------
We want to efficiently determine whether two elements belong to the same set
and merge sets when necessary. A naive approach using arrays or linked lists
would take O(n) for each operation. Using the Disjoint Set Union (DSU) data
structure with:
  1. Path Compression (in find operation)
  2. Union by Rank
We can reduce the amortized time complexity for each operation to nearly O(1).

Approach:
---------
1. Initialize each node as its own parent (self-loop) and set rank to 0.
2. To find the representative (ultimate parent) of a node:
   - Recursively move up the parent chain.
   - Apply path compression to flatten the structure for efficiency.
3. To union (merge) two sets:
   - Find the ultimate parents of both nodes.
   - Attach the tree with smaller rank to the one with larger rank.
   - If ranks are equal, attach one to the other and increment its rank.
4. This ensures minimal tree height and faster future lookups.
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent; // rank stores tree height; parent stores ultimate parent of each node
public:
    // Constructor: initializes parent and rank arrays
    DisjointSet(int n) {
        rank.resize(n + 1, 0);   // Initially, all ranks are 0
        parent.resize(n + 1);    // Parent array for all nodes (1-indexed here)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;       // Initially, each node is its own parent
        }
    }

    // Find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node]) // If node is its own parent, return it
            return node;
        // Recursively find the parent and apply path compression
        return parent[node] = findUPar(parent[node]);
    }

    // Union two sets by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Find ultimate parent of u
        int ulp_v = findUPar(v); // Find ultimate parent of v

        if (ulp_u == ulp_v) return; // They are already in the same set

        // Attach smaller rank tree under bigger rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // If ranks are equal, choose one as parent and increment rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    // Redirect input and output to files (for local testing only)
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Create DSU for 7 nodes
    DisjointSet ds(7);

    // Perform unions to merge sets
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if 3 and 7 belong to the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else {
        cout << "Not same\n";
    }

    // Merge sets containing 3 and 7
    ds.unionByRank(3, 7);

    return 0;
}
