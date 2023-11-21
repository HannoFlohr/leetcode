class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> value_indices;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            value_indices[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(value_indices[value].begin(), value_indices[value].end(), right)
             - lower_bound(value_indices[value].begin(), value_indices[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
 
 //https://leetcode.com/problems/range-frequency-queries/