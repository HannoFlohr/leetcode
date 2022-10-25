class MyHashSet {
private: 
    int hash_value;
    vector<list<int>> table;
    
    int hash(const int &key) {
        return key % hash_value; 
    }
    
    list<int>::iterator pos(const int &key) {
        int hashed = hash(key);
        return find(table[hashed].begin(), table[hashed].end(), key);
    }
    
public:
    MyHashSet() : hash_value(10007), table(hash_value) {}
    
    void add(int key) {
        int hashed = hash(key);
        if(!contains(key))
            table[hashed].push_back(key);
    }
    
    void remove(int key) {
        int hashed = hash(key);
        auto it = pos(key);
        if(it != table[hashed].end())
            table[hashed].erase(it);
    }
    
    bool contains(int key) {
        return pos(key) != table[hash(key)].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
 
 //https://leetcode.com/problems/design-hashset/