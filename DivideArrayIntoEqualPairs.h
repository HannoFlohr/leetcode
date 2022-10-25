class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const auto &n : nums)
            freq[n]++;
        
        for(const auto &f : freq)
            if(f.second % 2)
                return false;
        
        return true;
    }
};

//above: faster execution, more memory | O(n) O(n)
//below: slower execution, less memory | O(n log(n)) O(1)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i+=2)
            if(nums[i-1] != nums[i])
                return false;
        
        return true;
    }
};

//https://leetcode.com/problems/divide-array-into-equal-pairs/