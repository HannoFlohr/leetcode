class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> results (l.size(), true);

        for(int i = 0; i < l.size(); i++) {
            vector<int> sub (nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(sub.begin(), sub.end());
            int diff = sub[1] - sub[0];
            for(int j = 2; j < sub.size(); j++) {
                if(sub[j] - sub[j-1] != diff) {
                    results[i] = false;
                }
            }
        }

        return results;
    }
};
//https://leetcode.com/problems/arithmetic-subarrays/