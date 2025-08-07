class Solution {
  public:
    // Kahn's algorithm for topological sort
    vector<int> topoSort(int V, vector<int> adj[], vector<bool> &present) {
        vector<int> indegree(V, 0); // Store indegree of each node

        // Compute indegree for all nodes
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        // Push all nodes with 0 indegree (only if present in input)
        for (int i = 0; i < V; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo; // Stores the topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce indegree of neighbors
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

    string findOrder(vector<string> &words) {
        vector<int> adj[26];            // Adjacency list for characters 'a' to 'z'
        vector<bool> present(26, false); // Track which characters appear in the input

        // Step 1: Mark all characters that actually appear in the input words
        for (string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Step 2: Build the graph by comparing adjacent words
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string& s1 = words[i];
            string& s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            bool foundDifference = false;
            // Compare characters until a mismatch is found
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    // Edge from s1[j] → s2[j]
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    foundDifference = true;
                    break;
                }
            }

            // Step 2.1: Edge case check
            // If no mismatch found and s1 is longer than s2 (e.g., "abc" before "ab") → invalid
            if (!foundDifference && s1.size() > s2.size()) {
                return ""; // Not a valid dictionary order
            }
        }

        // Step 3: Perform topological sort on the graph
        vector<int> topo = topoSort(26, adj, present);

        // Step 4: Check for cycle
        // If not all present characters are in topo sort, it means there was a cycle
        int presentCount = 0;
        for (bool exists : present) {
            if (exists) presentCount++;
        }

        if (topo.size() != presentCount) {
            return ""; // Invalid ordering due to cycle
        }

        // Step 5: Build final result string from topological order
        string ans = "";
        for (int node : topo) {
            if (present[node]) {
                ans += (char)(node + 'a');
            }
        }

        return ans; // Return the inferred alien dictionary order
    }
};
