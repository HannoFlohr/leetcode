class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, mid, right = arr.size()-1;

        while(left < right) {
            mid = (left + right) / 2;

            if(arr[mid] < arr[mid+1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
//https://leetcode.com/problems/peak-index-in-a-mountain-array/