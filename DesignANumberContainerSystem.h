class NumberContainers {
private:
    unordered_map<int, int> index_number;
    unordered_map<int, set<int>> number_at_indices;

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        auto it = index_number.find(index);
        if(it != index_number.end()) {
            number_at_indices[it->second].erase(index);
        }
        index_number[index] = number;
        number_at_indices[number].insert(index);
    }
    
    int find(int number) {
        auto it = number_at_indices.find(number);
        return (it == number_at_indices.end() || it->second.empty()) ? -1 : *it->second.begin(); 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 
//https://leetcode.com/problems/design-a-number-container-system/