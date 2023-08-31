class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        
        int longest_chain = 0;
        for(int cmp = 0, cur = 0; cur < pairs.size(); ++cur) {
            if(cur == 0 || pairs[cmp][1] < pairs[cur][0]) {
                ++longest_chain;
                cmp = cur;
            }
        }
        
        return longest_chain;
    }
};
//https://leetcode.com/problems/maximum-length-of-pair-chain/