class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0LL, max_sum = -1LL;
        
        for(int num : nums) {
            sum += num;
            //to make a valid polygon: perimeter > 2 * length of longest side
            if(sum > num * 2) {
                max_sum = sum;
            }
        }

        return max_sum;
    }
};
https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/