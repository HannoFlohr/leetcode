class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int cur, n = nums.size();
        stack<int> numbers;
        vector<int> result (n,-1);
        
        for(int i=2*n-1; i>=0; i--) {
            cur = nums[i%n];
            
            while(!numbers.empty() && numbers.top() <= cur)
                numbers.pop();
            
            if(!numbers.empty())
                result[i%n] = numbers.top();
            
            numbers.push(cur);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/next-greater-element-ii/