class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        //cur min and max store the min/max product of subarray that ends at nums[i]
        int max_product = nums[0], cur_min = nums[0], cur_max = nums[0];
        
        for(int i=1; i<n; i++) {
            //swap extremums if negative number encountered
            if(nums[i] < 0) swap(cur_min, cur_max);
            
            //compute cur min/max for nums[i]
            cur_min = min(nums[i], cur_min * nums[i]);
            cur_max = max(nums[i], cur_max * nums[i]);
            
            //check if new overall maximum
            max_product = max(max_product, cur_max);
        }
    
        return max_product;
    }
};
//https://leetcode.com/problems/maximum-product-subarray/