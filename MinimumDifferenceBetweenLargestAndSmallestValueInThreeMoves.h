class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) {
            return 0;
        }
        const size_t n = nums.size();
        sort(nums.begin(), nums.end());
        /*
        solution can be optained by either:
        - changing the 3 smallest elements
        - changing the 2 smallest + 1 largest element
        - changing the 1 smallest + 2 largest elements
        - changing the 3 largest elements
        */
        return min({nums[n-1]-nums[3], nums[n-2]-nums[2], nums[n-3]-nums[1], nums[n-4]-nums[0]});
    }
};
//https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/