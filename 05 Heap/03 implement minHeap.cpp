Used GFG algos - q at codestudio
class minHeap {
public:
    vector<int> arr;
    int size;
    // Constructor for the class.
    minHeap() {
        // Write your code here.
        // Write your code here.
        size = 0;
        arr.reserve(100);
    }
    // Constructor with initial capacity
    minHeap(int capacity) {
        size = 0;
        arr.reserve(capacity);
    }
    
    void heapify(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if(left < size && arr[left] < arr[smallest]){
            smallest = left;
        }
        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        if(size == 0) return -1;
        int x = arr[0];

        arr[0] = arr[size-1];
        arr.pop_back();
        size--;

        heapify(0);
        return x;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if(ind >= size) return;
        // Write you code here.
        arr[ind] = arr[size-1];
        arr.pop_back();
        size--;
        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        size++;
        arr.push_back(val);
        int i = size-1;

        int parent = (i-1) / 2;
        while(i != 0 && arr[i] < arr[parent]){
            swap(arr[i], arr[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
};
