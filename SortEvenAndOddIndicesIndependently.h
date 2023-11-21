class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(int i = 0; i < nums.size(); i++) {
            if(i%2 == 0) {
                even.push_back(nums[i]);
            }
            else {
                odd.push_back(nums[i]);
            }
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());
        
        for(int i = 0, insert = 0; i < even.size(); i++, insert += 2) {
            nums[insert] = even[i];
            if(i != odd.size()) {
                nums[insert+1] = odd[i];;
            }
        }

        return nums;
    }
};
//https://leetcode.com/problems/sort-even-and-odd-indices-independently/