class SnapshotArray {
private:
    int id = 0;
    vector<vector<pair<int,int>>> memory;

public:
    SnapshotArray(int length) {
        memory = vector<vector<pair<int,int>>> (length);    
    }
    
    void set(int index, int val) {
        if(memory[index].empty() || memory[index].back().first != id)
            memory[index].push_back({id,val});
        else
            memory[index].back().second = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto ub = upper_bound(memory[index].begin(), memory[index].end(), pair<int,int>(snap_id, INT_MAX));
        return ub == memory[index].begin() ? 0 : prev(ub)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
 
 //https://leetcode.com/problems/snapshot-array/