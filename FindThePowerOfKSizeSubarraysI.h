class Solution {
public:
    vector<int> resultsArray(const vector<int>& nums, int k) {
        //all subarrays of length 1 are consecutive
        if(k == 1) {
            return nums;
        }
        
        const int n = nums.size();
        vector<int> result;
        
        for(int start = 0, end = 1; end < n; ++end) {
            //invalid sequence(s)
            if(nums[end] != nums[end-1]+1) {
                while(start < end && start+k-1 < n) {
                    result.push_back(-1);
                    ++start;
                }
                start = end;
            }
            //valid sequence
            else if(end-start+1 == k) {
                result.push_back(nums[end]);
                ++start;
            }
        }
            
        return result;
    }
};
//https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

/* first approach, also clears all TC

class Solution {
private:
    int isAscending(const vector<int>& nums, int start, int end) {
        for(int i = start+1; i <= end; ++i) {
            if(nums[i] != nums[i-1]+1)
                return -1;
        }
        return nums[end];
    }

public:
    vector<int> resultsArray(const vector<int>& nums, int k) {
        vector<int> result;
        for(int start = 0, end = k-1; end < nums.size(); ++start, ++end) 
            result.push_back(isAscending(nums, start, end));
        return result;
    }
};

*/