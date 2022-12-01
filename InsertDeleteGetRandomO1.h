class RandomizedSet {
private:
    vector<int> numbers;
    unordered_map<int,int> index_of_number;
    
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(index_of_number.find(val) != index_of_number.end()) 
            return false;
        
        numbers.push_back(val);
        index_of_number[val] = numbers.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(index_of_number.find(val) == index_of_number.end())
            return false;
        
        int last_number = numbers.back();
        index_of_number[last_number] = index_of_number[val];
        numbers[index_of_number[val]] = last_number;
        numbers.pop_back();
        index_of_number.erase(val);
        return true;
    }
    
    int getRandom() {
        return numbers[rand() % numbers.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
 //https://leetcode.com/problems/insert-delete-getrandom-o1/