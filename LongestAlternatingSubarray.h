class Solution {
private: 
    int lengthOfAlternatingStartingAt(int& index, const vector<int>& differences) {
        int length = 0, needed = 1;
        while(index < differences.size()) {
            if(differences[index] != needed) {
                return length;
            } 

            ++length;
            needed = (needed == 1 ? -1 : 1);
            ++index;
        }
        return length;
    }
public:
    int alternatingSubarray(vector<int>& nums) {
        int longest = 0, current = 0;

        vector<int> differences (nums.size(), 0);
        for(int i = 1; i < nums.size(); ++i) {
            differences[i] = nums[i] - nums[i-1];
        } 

        int index = 1;
        while(index < differences.size()) {
            if(differences[index] != 1) {
                ++index;
                continue;
            }
            longest = max(longest, lengthOfAlternatingStartingAt(index, differences));
        }

        return longest == 0 ? -1 : longest+1;
    }
};
//https://leetcode.com/problems/longest-alternating-subarray/