class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 0;

        for(int n : nums) {
            if(n > first) 
                second = first, first = n;
            else if(n > second)
                second = n;
        }

        return (first-1) * (second-1);
    }
};
//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

/* using partial sort
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        partial_sort(nums.begin(), nums.begin()+2, nums.end(), greater{});
        return (nums[0]-1) * (nums[1]-1);
    }
};
*/
