class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        
        for(size_t i = 0; i < nums.size()-1; i += 2) 
            result.insert(result.end(), nums[i], nums[i+1]);

        return result;
    }
};
//https://leetcode.com/problems/decompress-run-length-encoded-list/