class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, n = nums.size();
        
        for(int i = 1; i <= n; ++i) {
            if(n%i == 0) 
                sum += (nums[i-1] * nums[i-1]);    
        }

        return sum;
    }
};
//https://leetcode.com/problems/sum-of-squares-of-special-elements/