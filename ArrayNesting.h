class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n, length, max_length = 0;   
        
        for(int i=0; i<nums.size(); i++) {
            length = 0;
            for(int j=i; nums[j]>=0; length++) {
                n = nums[j];
                nums[j] = -1;
                j = n;
            }
            
            max_length = max(max_length, length);
        }
        
        return max_length;
    }
};
//https://leetcode.com/problems/array-nesting/