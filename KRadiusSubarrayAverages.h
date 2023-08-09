class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)
            return nums;

        vector<int> averages (nums.size(), -1);
        if(k > nums.size()/2)
            return averages;

        long sum = 0, elements = k*2+1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(i-elements >= 0)
                sum -= nums[i-elements];
            if(i >= elements-1)
                averages[i-k] = sum / elements;
        }

        return averages;
    }
};
//https://leetcode.com/problems/k-radius-subarray-averages/