class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] != nums[i+1]) continue;
            
            nums[i] *= 2;
            nums[i+1] = 0;
        }    

        stable_partition(nums.begin(), nums.end(), [](int &x){
            return x != 0; 
        } );
        
        return nums;
    }
};
//https://leetcode.com/problems/apply-operations-to-an-array/