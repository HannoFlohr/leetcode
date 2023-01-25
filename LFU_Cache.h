class LFUCache {
private: 
    int capacity, min_frequency;
    unordered_map<int, pair<int,int>> cache; //<key, <value, frequency>>
    unordered_map<int, list<int>> frequency_map; //<frequency, list of keys with that frequency>
    unordered_map<int, list<int>::iterator> frequency_iterator; //<key, iterator for list of key's frequency>

    void updateFrequency(const int& key) {
        //increment frequency for key
        int frequency = cache[key].second++;
        //remove from previous and append to new frequency list
        frequency_map[frequency].erase(frequency_iterator[key]); 
        frequency_map[frequency+1].push_front(key);
        //update iterator
        frequency_iterator[key] = frequency_map[frequency+1].begin();

        if(frequency_map[min_frequency].size() == 0) {
            frequency_map.erase(min_frequency);
            min_frequency++;
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        updateFrequency(key);

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        //key already in cache, update
        if(cache.find(key) != cache.end()) {
            updateFrequency(key);
            cache[key].first = value;
            return;
        }

        //key not in cache
        //check if there is room left in cache, remove least recently used otherwise
        if(cache.size() >= capacity) {
            int least_frequent_key = frequency_map[min_frequency].back();
            cache.erase(least_frequent_key);
            frequency_iterator.erase(least_frequent_key);
            frequency_map[min_frequency].pop_back();
        }
        //insert value
        cache[key] = {value, 1};
        min_frequency = 1;
        frequency_map[min_frequency].push_front(key);
        frequency_iterator[key] = frequency_map[min_frequency].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 //https://leetcode.com/problems/lfu-cache/