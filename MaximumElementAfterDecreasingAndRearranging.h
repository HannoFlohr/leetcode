class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int max_element = 0;

        for(int x : arr) {
            max_element = min(max_element+1, x);
        }

        return max_element;
    }
};
//https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

/*
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for(int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i-1]+1, arr[i]);
        }

        return arr.back();
    }
};
*/