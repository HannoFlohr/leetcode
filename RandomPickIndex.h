class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int target_index = -1, count = 0;
        
        for(int i = 0; i < this->nums.size(); ++i) {
            if(this->nums[i] != target) {
                continue;
            }

            ++count;
            if(rand() % count == 0) {
                target_index = i;
            }
        }

        return target_index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
 
 //https://leetcode.com/problems/random-pick-index/