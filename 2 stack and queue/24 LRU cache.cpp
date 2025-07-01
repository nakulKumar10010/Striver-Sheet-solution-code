class LRUCache {
public:
    // Doubly linked list node class
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Dummy head and tail nodes to avoid null checks
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;  // Maximum capacity of LRU cache
    unordered_map<int, node*> m;  // Key -> Node mapping for O(1) access

    // Constructor: Initialize capacity and link head and tail
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Add new node right after head (most recently used position)
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Delete a node from its current position
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Get the value of the key if it exists in cache
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];  // Get node pointer
            int res = resnode->val;   // Store value to return
            m.erase(key_);            // Remove from map temporarily
            deletenode(resnode);      // Remove node from current position
            addnode(resnode);         // Move node to front (MRU position)
            m[key_] = head->next;     // Update map with new position
            return res;               // Return value
        }

        return -1;  // Key not found
    }

    // Insert or update a value
    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node* existingnode = m[key_];  // Get existing node
            m.erase(key_);                 // Remove from map
            deletenode(existingnode);      // Remove node from list
        }
        if (m.size() == cap) {
            // If at capacity, remove least recently used (node before tail)
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // Add new node at front (MRU position)
        addnode(new node(key_, value));
        m[key_] = head->next;  // Update map
    }
};
