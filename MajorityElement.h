class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], count = 1; 
        
        for(int i=1; i<nums.size(); i++) {
            if(count == 0) {
                count++;
                majority = nums[i];
            }
            else if(majority == nums[i])
                count++;
            else
                count--;
        }
        
        return majority;
    }
};
//https://leetcode.com/problems/majority-element/

//https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
//https://www.cs.rug.nl/~wim/pub/whh348.pdf