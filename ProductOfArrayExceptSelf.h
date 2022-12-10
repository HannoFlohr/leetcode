class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), pre = 1, post = 1; 
        vector<int> answer (n, 1);
        
        for(int i=0; i<n; i++) {
            answer[i] *= pre;
            pre *= nums[i];
            
            answer[n-1-i] *= post;
            post *= nums[n-1-i];
        }
        
        return answer;
    }
};
//https://leetcode.com/problems/product-of-array-except-self/