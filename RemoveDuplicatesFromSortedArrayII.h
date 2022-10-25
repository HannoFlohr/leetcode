class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
		//loop through nums and include those in the result that havent been included twice
        for(int n:nums)
            if(i<2 || n>nums[i-2])
                nums[i++] = n;
        
        return i;
    }
};
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

/*

class Solution {
private:
    void rem(vector<int>& nums, int &i, int &count) {
        nums.erase( nums.begin()+(i-1)-(count-2) , nums.begin()+(i-1) );
        i -= (count-2);
    }
    
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                count++;
                if(i==nums.size()-1)
                    rem(nums, i, count);
            }
            else {
                if(count > 2) 
                    rem(nums, i, count);
                count = 1;
            }
        }
        
        return nums.size();
    }
};

*/