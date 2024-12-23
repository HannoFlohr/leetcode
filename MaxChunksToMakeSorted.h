class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_chunks = 0;

        for(int i = 0, sum_index = 0, sum_array = 0; i < arr.size(); ++i) {
            sum_index += i;
            sum_array += arr[i];
            if(sum_index == sum_array) 
                ++max_chunks;
        }

        return max_chunks;
    }
};
//https://leetcode.com/problems/max-chunks-to-make-sorted/

/*

class Solution {
private:
    bool foundUpTo(const vector<bool>& found, int limit) {
        for(int i = 0; i <= limit; ++i) {
            if(found[i] == false)  
                return false;
        }
        return true;
    }
    
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), max_chunks = 0;
        vector<bool> found (n, false);

        for(int i = 0; i < n; ++i) {
            found[arr[i]] = true;
            if(foundUpTo(found, i)) 
                ++max_chunks;
        }

        return max_chunks;
    }
};

*/