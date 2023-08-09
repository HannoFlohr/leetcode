/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int peakIndexInMountainArray(MountainArray& arr) {
        int left = 0, mid, right = arr.length()-1;
        while(left < right) {
            mid = (left + right) / 2;

            if(arr.get(mid) < arr.get(mid+1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int find(int target, int left, int right, MountainArray& mountainArr, bool leftOfPeak) {
        int mid, mid_value;
        while(left <= right) {
            mid = (left+right) / 2;
            mid_value = mountainArr.get(mid);

            if(mid_value == target) 
                return mid;

            if(leftOfPeak == (mid_value < target)) 
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int peak_index = peakIndexInMountainArray(mountainArr);
        int target_index = find(target, 0, peak_index, mountainArr, true);
        return target_index != -1 ? target_index : find(target, peak_index+1, mountainArr.length()-1, mountainArr, false);
    }
};
//https://leetcode.com/problems/find-in-mountain-array/