class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        double min_average = std::numeric_limits<double>::max();
        int front = 0, back = nums.size()-1;
        while(front < back) {
            min_average = min(min_average, (nums[back--] + nums[front++]) / 2.0);
        }

        return min_average;
    }
};
//https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/