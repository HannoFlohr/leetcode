class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, result = 0;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            //ceil average of sum ceil(double(sum) / (i+1)) -> integer division: (sum + i)/(i + 1)
            result = max(result, (sum + i)/(i + 1)); 
        }

        return result;
    }
};
//https://leetcode.com/problems/minimize-maximum-of-array/