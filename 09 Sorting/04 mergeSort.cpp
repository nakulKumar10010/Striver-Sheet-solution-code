class Solution {
  public:
    
    // Function to merge two sorted subarrays of arr
    // Left subarray: arr[l..mid], Right subarray: arr[mid+1..r]
    void mergeSortdArray(vector<int>& arr, int l, int r, int mid) {
        vector<int> temp; // Temporary array to store merged result
        int i = l;        // Pointer for left subarray
        int j = mid + 1;  // Pointer for right subarray
        
        // Compare elements from both subarrays and store smaller one in temp
        while(i <= mid && j <= r){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        // Copy remaining elements from left subarray (if any)
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        // Copy remaining elements from right subarray (if any)
        while(j <= r){
            temp.push_back(arr[j]);
            j++;
        }
        
        // Copy back the merged elements into original array
        for(int k = l; k <= r; k++){
            arr[k] = temp[k - l];  // Adjust index since temp starts from 0
        }
    }

    // Recursive Merge Sort function
    void mergeSort(vector<int>& arr, int l, int r) {
        // Base case: If single element or invalid range, stop recursion
        if(l >= r) return;
        
        // Find middle index
        int mid = (l + r) / 2;
        
        // Recursively sort left half: arr[l..mid]
        mergeSort(arr, l, mid);
        
        // Recursively sort right half: arr[mid+1..r]
        mergeSort(arr, mid+1, r);
        
        // Merge the two sorted halves
        mergeSortdArray(arr, l, r, mid);
    }
};
