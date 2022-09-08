class Solution { 
    
void reverse(vector<int>& nums, int start) {
    int i=start, j=nums.size()-1;
    while(i<j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}
    
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 2;
        while(index >= 0 && nums[index+1] <= nums[index])
            index--;
        
        if(index>=0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[index])
                j--;
            
            swap(nums[index], nums[j]);
        }

        reverse(nums, index+1);
    } 
};
//https://leetcode.com/problems/next-permutation/
/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
*/