class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size(); 
        int left = 0, right = n-1;

        //find first decreasing index from left 
        while(left+1 < n && arr[left] <= arr[left+1])
            ++left;
        //already completely sorted
        if(left == n-1)
            return 0;
        //find first increasing index from right
        while(right > left && arr[right-1] <= arr[right])
            --right;
        //find length of subarray to be removed
        int length = min(n-left-1, right), i = 0, j = right;
        while(i <= left && j < n) {
            if(arr[j] >= arr[i]) {
                length = min(length, j-i-1);
                ++i;
            }
            else
                ++j;
        }

        return length;
    }
};
//https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/