class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int n = nums.size();
        vector<int> odd_before(n,0), odd_after(n,0), even_before(n,0), even_after(n,0);

        for(int i = 1; i < n; i += 2) {
            even_before[i] = even_before[i-1] + nums[i-1];
            if(i+1 < n) {
                even_before[i+1] = even_before[i];
            }
        }
        for(int i = 2; i < n; i += 2) {
            odd_before[i] = odd_before[i-1] + nums[i-1];
            if(i+1 < n) {
                odd_before[i+1] = odd_before[i];
            }
        }
        for(int i = n-2; i >= 0; --i) {
            if(i%2 == 0) {
                odd_after[i] = odd_after[i+1] + nums[i+1];
                if(i-1 >= 0) {
                    odd_after[i-1] = odd_after[i];
                }
            }
            else {
                even_after[i] = even_after[i+1] + nums[i+1];
                if(i-1 >= 0) {
                    even_after[i-1] = even_after[i];
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(even_before[i]+odd_after[i] == odd_before[i]+even_after[i]) {
                ++count;
            }
        }
        return count;
    }
};
//https://leetcode.com/problems/ways-to-make-a-fair-array/