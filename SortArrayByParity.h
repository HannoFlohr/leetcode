//return new vector 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> sorted;
        for(int num : nums) {
            if(num % 2 == 0) {
                sorted.insert(sorted.begin(), num);
            }
            else {
                sorted.push_back(num);
            }
        }
        return sorted;
    }
};
//https://leetcode.com/problems/sort-array-by-parity/

//in-place swap
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int cur = 0, swap_index = 0; cur < nums.size(); cur++) {
            if(nums[cur] % 2 == 0) {
                if(cur != swap_index) {
                    swap(nums[cur], nums[swap_index]);
                }
                swap_index++;
            }
        }
        return nums;
    }
};