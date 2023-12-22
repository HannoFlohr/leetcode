class Solution {
public:
    int findLHS(vector<int>& nums) {
        int lhs = 0;
        map<int,int> values;
        
        for(int n : nums){
            values[n]++;
        }
        for(map<int,int>::iterator it = next(values.begin()); it != values.end(); it++) {
            if(it->first - prev(it)->first != 1) {
                continue;
            }
            lhs = max(lhs, it->second + prev(it)->second);
        }

        return lhs;
    }
};
//https://leetcode.com/problems/longest-harmonious-subsequence/