class Solution {
private: 
    void countSubsets(vector<int>& nums, int k, int index, unordered_map<int,int>& in_subset, int& count) {
        //end reached, increment count
        if(index == nums.size()) {
            ++count;
            return;
        }

        int num = nums[index];
        //check if num +/- k is already in the current subset, if so current number can't be taken
        if(in_subset[num-k] == 0 && in_subset[num+k] == 0) {
            //mark num as in subset
            in_subset[num]++;
            //count possible subsets including num
            countSubsets(nums, k, index+1, in_subset, count);
            //backtrack mark for num
            in_subset[num]--;
        }

        //count possible subsets without num
        countSubsets(nums, k, index+1, in_subset, count);
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> in_subset;
        countSubsets(nums, k, 0, in_subset, count);
        return count - 1;
    }
};
//https://leetcode.com/problems/the-number-of-beautiful-subsets/