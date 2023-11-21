class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_freq = 1;

        for(int right = nums.size()-1, left = right; right > 0; right--) {
            for( ; left >= 0 && k >= nums[right]-nums[left]; left--) {
                k -= nums[right] - nums[left];
            }
            max_freq = max(max_freq, right-left);

            k += (nums[right]-nums[right-1]) * (right-left-1);
        }

        return max_freq;
    }
};
//https://leetcode.com/problems/frequency-of-the-most-frequent-element/

/* first approach 5TC passed

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int value, left, right, remaining, max_freq = 0;

        for(int start = 0; start < n; start++) {
            value = nums[start], remaining = k;
            left = start-1, right = start+1;
            
            while(left > 0 && nums[left] == value)
                --left;
            while(right < n && nums[right] == value)
                ++right;

            while(remaining > 0) {
                int diff_left = INT_MAX, diff_right = INT_MAX;
                if(left > 0)
                    diff_left = value - nums[left];
                if(right < n)
                    diff_right = nums[right] - value;

                if(diff_left < diff_right && diff_left <= remaining) {
                    remaining -= diff_left;
                    --left;
                }
                else if(diff_right <= remaining) {
                    remaining -= diff_right;
                    ++right;
                }
                else {
                    break;
                }
            }
            
            max_freq = max(max_freq, right-left-1);
        }

        return max_freq;
    }
};

*/