class Solution {
private:
    vector<int> origin;
    int size;
public:
    Solution(vector<int>& nums) {
        origin = nums;
        size = nums.size();
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        int seed = size;
        vector<int> shuffled = origin;
        
        for(int old_index = size-1; old_index >= 0; old_index--) {
            int new_index = rand() % seed;
            swap(shuffled[old_index], shuffled[new_index]);
            seed--;
        }

        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 
 //https://leetcode.com/problems/shuffle-an-array/