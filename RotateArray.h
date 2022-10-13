class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k %= n;
        if(k == 0) return;
        
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n -k, nums.begin() + n);
        reverse(nums.begin(), nums.begin() + n);
    }
};
//https://leetcode.com/problems/rotate-array/

/*
for example 
1 2 3 4 5 6 7 with k=3

1) reverse first n-k elements
4 3 2 1 5 6 7

2) reverse last k elements
4 3 2 1 7 6 5

3) reverse all elements
5 6 7 1 2 3 4

*/