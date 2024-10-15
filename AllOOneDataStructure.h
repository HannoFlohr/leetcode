struct Count {
    int value;
    unordered_set<string> keys;
};

class AllOne {
private:
    list<Count> counts;
    unordered_map<string, list<Count>::iterator> countOfKey;

public:
    AllOne() {
    }
    
    void inc(string key) { //cout<<"inc "<<key<<endl;
        //new key
        if(!countOfKey.contains(key)) 
            countOfKey[key] = counts.insert(counts.begin(), {0, {key}});

        //add key to next higher count
        auto next = countOfKey[key], old = next++; 
        if(next == counts.end() || next->value > old->value+1) //create new count if needed
            next = counts.insert(next, {old->value+1, {}});
        next->keys.insert(key);
        countOfKey[key] = next;

        //remove key from old count
        old->keys.erase(key);
        if(old->keys.empty())
            counts.erase(old);
    }
    
    void dec(string key) { //cout<<"dec "<<key<<endl;
        //check if key exists
        if(!countOfKey.contains(key))
            return;

        //add key to lower count
        auto lower = countOfKey[key], old = lower--;
        countOfKey.erase(key);
        if(old->value > 1) {
            if(old == counts.begin() || lower->value < old->value-1)
                lower = counts.insert(old, {old->value-1, {}});
            lower->keys.insert(key);
            countOfKey[key] = lower;
        }

        //remove key from old count
        old->keys.erase(key);
        if(old->keys.empty())
            counts.erase(old);
    }
    
    string getMaxKey() {
        return counts.empty() ? "" : *(counts.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return counts.empty() ? "" : *(counts.begin()->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
 
 //https://leetcode.com/problems/all-oone-data-structure/