class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size()-1;
        vector<int> count (n+1, 0);
        
        for(int num : nums) {
            if(num > n) {
                return false;
            }
            
            count[num]++;

            if(count[num] > 2 || (count[num] == 2 && num != n)) {
                return false;
            } 
        }

        return true;
    }
};
//https://leetcode.com/problems/check-if-array-is-good/