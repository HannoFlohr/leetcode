class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long badPairs = 0;
        unordered_map<int,int> differences; //count of elements with difference nums[i] - i

        for(size_t i=0; i<nums.size(); i++) {
            //elements with same difference are good pairs; with different differences bad pairs
			//i possible new pairs - amount of pairs with same difference 
            badPairs += i - differences[nums[i] - i];
            differences[nums[i] - i]++;
        }

        return badPairs;
    }
};
//https://leetcode.com/problems/count-number-of-bad-pairs/