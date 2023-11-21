class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v (n);
        int left = 0, right = n-1, cur_value = n/2;

        while(left <= right) {
            v[left] = -cur_value;
            v[right] = cur_value;
            --cur_value;
            ++left;
            --right;
        }

        return v;
    }
};
//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/