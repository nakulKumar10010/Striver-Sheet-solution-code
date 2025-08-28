// Approach & Intuition:
// ----------------------
// The problem asks us to replace each element of the array with its "rank" based on sorted order.  
// - Rank starts from 1 for the smallest element.  
// - Equal elements should get the same rank.  
//
// Example: arr = [20, 15, 26, 2, 98, 6]  
// Sorted = [2, 6, 15, 20, 26, 98]  
// Ranks = [4, 3, 5, 1, 6, 2]
//
// Intuition:
// Instead of sorting the array directly and losing the original index positions,  
// we use a **priority_queue (min-heap)** to store (value, index).  
// - This ensures elements are extracted in ascending order.  
// - While popping elements, we assign rank in increasing order.  
// - If the current value is the same as the last one, we assign the same rank.  
// - Otherwise, increment the rank.  
// - Finally, place the rank at the correct original index.
//
// Time Complexity: O(N log N) (for heap operations)
// Space Complexity: O(N) (for heap + answer vector)


// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // Min-heap storing {value, index}
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 1: Push all elements into min-heap with their index
        for(int i = 0; i < N; i++){
            pq.push({arr[i], i});
        }

        // Step 2: Prepare answer vector initialized with -1
        vector<int> ans(N, -1);

        int rank = 0;               // Current rank
        int lastValue = INT_MIN;    // To handle duplicate values

        // Step 3: Extract elements in sorted order
        while(!pq.empty()){
            int currValue = pq.top().first;   // Current element value
            int ind = pq.top().second;        // Original index of element
            pq.pop();
            
            // If new value encountered, increment rank
            if(lastValue != currValue){
                rank++;
                lastValue = currValue;
            }

            // Assign rank to original index
            ans[ind] = rank;
        }
        
        return ans;
    }
};
