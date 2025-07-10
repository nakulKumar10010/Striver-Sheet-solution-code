// User function Template for C++

class Solution {
  public:
    // Function to ensure Max-Heap property is maintained at index 'i'
    void heapify(int i, int n, vector<int> &arr){
        int left = 2 * i + 1;   // Index of the left child in a 0-based array
        int right = 2 * i + 2;  // Index of the right child in a 0-based array
        int largest = i;        // Initially assume the current node is the largest

        // Check if left child exists and is greater than the current largest
        if(left < n && arr[largest] < arr[left]){
            largest = left;  // Update largest to left child's index
        }

        // Check if right child exists and is greater than the current largest
        if(right < n && arr[largest] < arr[right]){
            largest = right;  // Update largest to right child's index
        }

        // If largest is not the current node, we need to swap and fix the subtree
        if(largest != i){
            swap(arr[i], arr[largest]);  // Swap current node with the larger child
            // Recursively call heapify on the affected child node to continue fixing the tree
            heapify(largest, n, arr);
        }
    }

    // Function to convert a Min-Heap to a Max-Heap
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        /*
         * In a heap, all leaf nodes are already valid heaps by themselves.
         * So we only need to start heapifying from the last non-leaf node
         * and go up to the root node.
         *
         * In a complete binary tree (heap):
         * - Last non-leaf node is at index (N/2 - 1)
         * - Leaf nodes are from index (N/2) to (N - 1)
         */

        for(int i = N/2 - 1; i >= 0; i--){
            // Heapify each internal node from bottom up to the root
            heapify(i, N, arr);
        }

        /*
         * After this loop, the entire array will satisfy the Max-Heap property:
         * For every node arr[i], it holds that:
         * - arr[i] >= arr[2*i + 1] (left child)
         * - arr[i] >= arr[2*i + 2] (right child)
         */
    }
};

🧠 Revision Concepts You Should Remember
1. Heap Basics
A heap is a complete binary tree.

Max-Heap: Every parent ≥ both children.

Min-Heap: Every parent ≤ both children.

2. Heap Representation
Stored as an array.

For index i:

Left child → 2*i + 1

Right child → 2*i + 2

Parent → (i - 1)/2

3. Why Start From N/2 - 1
Nodes from index N/2 to N-1 are leaf nodes and already satisfy heap property.

We only need to fix internal nodes.
