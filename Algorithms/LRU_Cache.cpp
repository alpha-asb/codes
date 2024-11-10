class LRUCache {
  
  struct Node {
      int key;
      int val;
      Node* prev;
      Node* next;
      Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
  };
  
  unordered_map<int, Node*> mp;
  int capacity;
  int count;
  Node* head;
  Node* tail;

  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        count = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void InsertAtFront(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
    if (mp.find(key) != mp.end()) {
        Node* temp = mp[key];
        int val = temp->val;
        remove(temp); // Move it to the front
        InsertAtFront(temp);
        return val;
    } else {
        return -1; // Key not found
    }
}

    // Function for storing key-value pair.
    void set(int key, int value) {
    if (mp.find(key) != mp.end()) { // Key exists, update value and move to front
        Node* temp = mp[key];
        temp->val = value; // Update the value
        remove(temp); // Remove from current position
        InsertAtFront(temp); // Move to front
    } else { // Key doesn't exist, add new node
        Node* node = new Node(key, value);
        mp[key] = node;
        InsertAtFront(node);

        if (count < capacity) {
            count++;
        } else { // Cache is full, remove LRU
            Node* last = tail->prev;
            mp.erase(last->key); // Remove from map
            remove(last); // Remove from list
            delete last;
        }
    }
}

};
