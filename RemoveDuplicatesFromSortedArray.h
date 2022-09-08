class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase( unique(nums.begin(), nums.end()), nums.end() );   
        return nums.size();
    }
};
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) 
            if(nums[i]==nums[i+1]) {
                nums.erase(nums.begin()+i);
                i--;
            }    
        
        return nums.size();
    }
};
*/