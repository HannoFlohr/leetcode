class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> streakAtNumber;

        for(int n : nums) {
            int root = (int)sqrt(n);

            if(root*root == n && streakAtNumber.contains(root))
                streakAtNumber[n] = streakAtNumber[root] + 1;
            else
                streakAtNumber[n] = 1;
        }

        int longest = 1;
        for(auto& [_,streak] : streakAtNumber)
            longest = max(longest, streak);

        return longest == 1 ? -1 : longest;
    }
};
//https://leetcode.com/problems/longest-square-streak-in-an-array/