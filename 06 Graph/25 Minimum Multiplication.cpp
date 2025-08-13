// Intuition:
// We are given a start number, an end number, and an array of integers.
// From the current number, we can multiply it by any number in the array,
// and then take the result modulo 100000.  
// We need to find the minimum number of multiplications required to reach `end` from `start`.
// This can be visualized as an unweighted graph problem where each number (0–99999) is a node,
// and an edge exists between two numbers if one can be obtained from the other
// by multiplying with any element in `arr` and taking modulo 100000.
// Since each multiplication counts as 1 step, we can use BFS to find the shortest path.
//
// Approach:
// 1. Treat each possible value modulo 100000 as a node in the graph.
// 2. Use BFS starting from `start` because all edges have equal weight (1 step).
// 3. Maintain a `dist` array to store the minimum steps to reach each value.
// 4. For each number, multiply it with every element in `arr` and take modulo 100000.
// 5. If the new value can be reached in fewer steps, update `dist` and push it to the queue.
// 6. Stop BFS when `end` is reached; otherwise return -1 if unreachable.

class Solution {
  public:
    const int MOD = 100000; // Modulo value as given in problem

    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Stores minimum steps to reach each value (0 to 99999)
        vector<int> dist(100000, INT_MAX);

        // Queue for BFS: stores {steps, node}
        queue<pair<int, int>> q;
        
        // Starting point
        dist[start] = 0;
        q.push({0, start});
        
        // BFS traversal
        while(!q.empty()){
            int node = q.front().second; // Current number
            int steps = q.front().first; // Steps taken so far
            q.pop();

            // If we reached the target number
            if(node == end) return steps;

            // Try multiplying with all elements in arr
            for(auto it : arr){
                int newValue = (node * it) % MOD; // New value after multiplication and modulo
                
                // If we found a shorter path to newValue
                if(dist[newValue] > steps + 1){
                    dist[newValue] = steps + 1;
                    q.push({dist[newValue], newValue});
                }
            }
        }
        
        // If end is unreachable
        return -1;
    }
};
