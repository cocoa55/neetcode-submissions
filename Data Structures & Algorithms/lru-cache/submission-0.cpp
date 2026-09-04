class LRUCache {
    int _capacity;
    std::list<std::pair<int, int>> items; //<key, value>
    unordered_map<int, typename std::list<std::pair<int, int>>::iterator> lookup; //<key, node>

    void touch(typename std::list<std::pair<int, int>>::iterator itr)
    {
    items.splice(items.begin(), items, itr);
    }
public:
    LRUCache(int capacity) :
    _capacity(capacity)
    {
        
    }
    
    int get(int key) {
        auto itr = lookup.find(key); //finds the value (node)
    
        if (itr != lookup.end()) {
        touch(itr->second); //sets to the head
        return itr->second->second; //return the value at the list iterator(node)
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
    auto itr = lookup.find(key); 

    if (itr != lookup.end()) { //if it exists
        itr->second->second = value; //update the node value
        touch(itr->second); //set it to the front
        return;
    }
    if(_capacity == items.size()) {
    auto& back = items.back();
    lookup.erase(back.first); //dont keep track of this item anymore
    items.pop_back(); //remove last item
    }
    items.emplace_front(key, value);
    lookup[key] = items.begin(); //map the key, to a pointer to the head.
    }
};
