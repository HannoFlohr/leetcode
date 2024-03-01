class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> nums (arr.begin(), arr.end());
        
        map<int,int> ranks;
        int rank = 1;
        for(int num : nums) {
            ranks[num] = rank++;
        }

        vector<int> result (arr.size());
        for(int i = 0; i < arr.size(); ++i) {
            result[i] = ranks[arr[i]];
        }

        return result;
    }
};
//https://leetcode.com/problems/rank-transform-of-an-array/