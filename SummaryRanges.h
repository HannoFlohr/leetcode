class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> result;
        
        for(int end=0, start=0; end<n; end++) {
            if(end == n-1 || nums[end]+1 != nums[end+1]) {
                result.push_back( to_string(nums[start]) + ((start==end) ? "" : "->" + to_string(nums[end])) );

                start = end+1; 
            }
        }
        
        return result;
    }
};
//https://leetcode.com/problems/summary-ranges/