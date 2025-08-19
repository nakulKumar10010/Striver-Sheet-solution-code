// -----------------------------
// Disjoint Set Union (Union-Find)
// -----------------------------
class DisjointSet {
public:
    vector<int> parent, size;

    // Constructor: initialize parent and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);   // parent[i] = parent of node i
        size.resize(n + 1, 1);  // size[i] = size of set where i belongs (default 1)

        // Initially, every node is its own parent (self root)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression:
    // - Returns the "ultimate parent" (representative) of the node
    // - While doing so, compresses the path by directly linking node → root
    int findUPar(int node) {
        if (node == parent[node]) {
            return node; // base case: node is its own parent
        }
        // Recursive call + path compression
        return parent[node] = findUPar(parent[node]);
    }

    // Union by size:
    // - Connects two nodes u and v by attaching the smaller set under the bigger set
    void unionBySize(int u, int v) {
        int pu = findUPar(u); // ultimate parent of u
        int pv = findUPar(v); // ultimate parent of v

        if (pu == pv)
            return; // already in the same set

        // Attach smaller set under bigger set
        if (size[pu] < size[pv]) {
            parent[pu] = pv;         // connect pu → pv
            size[pv] += size[pu];    // update size of pv's set
        } else {
            parent[pv] = pu;         // connect pv → pu
            size[pu] += size[pv];    // update size of pu's set
        }
    }
};

// -----------------------------
// Accounts Merge Solution
// -----------------------------
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(); // number of accounts
        DisjointSet ds(n);       // DSU for 'n' accounts

        // Step 1: Map each email to an account index
        // (If an email is already mapped, union current account with previous one)
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            // Start from j=1 because index 0 is the account holder's name
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                // If this email is not seen before → map it to account i
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } 
                // If this email already belongs to some other account
                // → union the two accounts because they must belong to the same person
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails based on ultimate parent
        // - Each parent index will hold a vector of all emails belonging to it
        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second); // find parent of the account containing this mail
            mergedMail[node].push_back(mail);  // group mail under its parent
        }

        // Step 3: Build the final answer
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0)
                continue; // skip if no emails for this parent

            // Sort emails for lexicographical order (as required by problem)
            sort(mergedMail[i].begin(), mergedMail[i].end());

            // Start a temporary vector with the account holder's name
            vector<string> temp;
            temp.push_back(accounts[i][0]); // person name

            // Add all emails belonging to this person
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
