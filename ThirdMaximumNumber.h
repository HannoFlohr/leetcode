class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top;
        for(auto &n : nums) 
            top.insert(n);

        return top.size() >= 3 ? *(next(top.rbegin(), 2)) : *top.rbegin();
    }
};
//https://leetcode.com/problems/third-maximum-number/submissions/