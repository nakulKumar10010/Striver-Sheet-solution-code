class Solution {
  public:
    // QuickSort function
    void quickSort(vector<int>& arr, int low, int high) {
        // Base condition: run only if at least 2 elements exist
        if(low < high){
            // Partition the array around a pivot and get pivot index
            int partitionIndex = partition(arr, low, high);
            
            // Recursively sort elements before pivot
            quickSort(arr, low, partitionIndex - 1);
            
            // Recursively sort elements after pivot
            quickSort(arr, partitionIndex + 1, high);
        }
    }

  public:
    // Partition function: rearranges array elements around pivot
    int partition(vector<int>& arr, int low, int high) {
        
        int i = low;    // Pointer from left
        int j = high;   // Pointer from right
        int pivot = low; // Choosing the first element as pivot
        
        // Rearrange elements around pivot
        while(i < j){
            // Move i rightwards until we find element greater than pivot
            while(arr[i] <= arr[pivot] && i <= high - 1){
                i++;
            }
            
            // Move j leftwards until we find element smaller than pivot
            while(arr[j] > arr[pivot] && j >= low + 1){
                j--;
            }
            
            // If valid, swap out-of-place elements
            if(i < j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Place pivot element at its correct sorted position
        int temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        
        // Return final index of pivot
        return j;
    }
};
