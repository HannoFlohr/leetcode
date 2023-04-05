class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;

        vector<int> nums (n+1);
        nums[0] = 0, nums[1] = 1;
        int index1 = 1, index2 = 2;

        for(int i=2; i<=n; i++) {
            if(i%2 == 0) 
                nums[i] = nums[index1];
            else 
                nums[i] = nums[index1++] + nums[index2++]; 
        }

        return *max_element(nums.begin(), nums.end());
    }
};
//https://leetcode.com/problems/get-maximum-in-generated-array/