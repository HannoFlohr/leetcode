class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0, r;
        unordered_set<int> s (nums.begin(), nums.end());
        
        for(auto &n : s) {
            if(s.count(n-1)) continue; //if n and n-1 are in set, the sequence starting at n-1 will always be longer
            
			//count consecutive numbers to the right
            r = 1;
            while(s.count(n + r)) r++;
            
            longest = max(longest, r); //new max found?
        }
        
        return longest;
    }
};
//https://leetcode.com/problems/longest-consecutive-sequence/