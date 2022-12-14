class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a, b, c;
        for(auto &t : triplets)
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                a = max(a, t[0]);
                b = max(b, t[1]);
                c = max(c, t[2]);
            }

        return a == target[0] && b == target[1] && c == target[2] ? true : false;
    }
};
//https://leetcode.com/problems/merge-triplets-to-form-target-triplet/