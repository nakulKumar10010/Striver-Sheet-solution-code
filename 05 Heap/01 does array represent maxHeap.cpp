class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Only check internal nodes (i from 0 to (n-2)/2) // check before leaf node level
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Check left child
            if (left < n && arr[i] < arr[left])
                return false;

            // Check right child
            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};

🔍 Explanation:
You only need to iterate from index 0 to (n-2)/2 because all nodes beyond this are leaf nodes and do not have children.

This avoids redundant checks and keeps the code focused and efficient.

💡 Time Complexity:
O(n) — as we visit each internal node once.

Space Complexity: O(1) — no extra space is used.

  //mine '
  bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i = 0; i < n; i++){
            //left child
            if(2*i + 1 < n){
                if(arr[i] < arr[2*i + 1])
                    return false;
            }
            //right child
            if(2*i + 2 < n){
                if(arr[i] < arr[2*i + 2])
                    return false;
            }
        }
        
        return true;
    }
