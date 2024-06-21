class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        int max_length = 0;

        for(int end = 0, start = 0; end < nums.size(); ++end) {
            frequency[nums[end]]++;

            while(frequency[nums[end]] > k) {
                frequency[nums[start++]]--;
            }

            max_length = max(max_length, end-start+1);
        }

        return max_length;
    }
};
//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

/* first approach below using queue and frequency map; above simplified to sliding window without queue
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        queue<int> q; 
        int max_length = 0;

        for(int num : nums) {
            frequency[num]++; 
            q.push(num);

            if(frequency[num] <= k) {
                max_length = max(max_length, (int)q.size());
                continue;
            }

            while(q.front() != num) {
                frequency[q.front()]--;
                q.pop();
            } 
            frequency[q.front()]--;
            q.pop();
        }

        return max_length;
    }
};
*/