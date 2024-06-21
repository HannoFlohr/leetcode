class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs ({{}});
        
        for(int num : nums) {
            //copy current subsets
            vector<vector<int>> subsTmp = subs;
            //add the new number to each of the copied subsets
            for(vector<int>& sub : subs)
                sub.push_back(num);
            //add the updated subsets to the overall ones
            for(int j = 0; j < subsTmp.size(); ++j)
                subs.push_back(subsTmp[j]);
        }
        
        return subs;
    }
};
//https://leetcode.com/problems/subsets/