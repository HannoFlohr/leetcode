class LRUCache {
private:
    list< pair<int,int> > items;
    unordered_map<int, decltype(items.begin())> key_to_list;
    size_t cache_size;

    void cleanup() {
        while(key_to_list.size() > cache_size) {
            auto it_last = items.end(); 
            it_last--;
            key_to_list.erase(it_last->first);
            items.pop_back();
        }
    }

public:
    LRUCache(int capacity) : cache_size(capacity) {}
    
    int get(int key) {
        auto it = key_to_list.find(key);
        if(it == key_to_list.end())
            return -1;
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = key_to_list.find(key);
        if(it != key_to_list.end()) {
            items.erase(it->second);
            key_to_list.erase(it);
        }

        items.push_front(make_pair(key,value));
        key_to_list.insert(make_pair(key, items.begin()));
        cleanup();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 //https://leetcode.com/problems/lru-cache/