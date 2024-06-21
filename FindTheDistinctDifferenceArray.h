class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> difference;
        unordered_map<int,int> prefix, suffix;
        for(int n : nums) {
            ++suffix[n];
        }
    
        for(int n : nums) {
            ++prefix[n];
            if(--suffix[n] == 0) {
                suffix.erase(n);
            }
            difference.push_back(prefix.size() - suffix.size());
        }

        return difference;
    }
};
//https://leetcode.com/problems/find-the-distinct-difference-array/