class Solution {  
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0, count = 0, odd = 0;
    
        for(int start = 0, end = 0; end < nums.size(); ++end) {
            if(nums[end] % 2 == 1) {
                odd++;
                if(odd >= k) {
                    count = 1;
                    while(nums[start++] % 2 == 0) {
                        ++count;
                    }
                    subarrays += count;
                }
            }
            else if(odd >= k) {
                subarrays += count;
            }
        }

        return subarrays;
    }
};
//https://leetcode.com/problems/count-number-of-nice-subarrays/