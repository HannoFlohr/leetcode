class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int x, greatest = -1;
        for(int i = arr.size()-1; i >= 0; --i) {
            x = arr[i];
            arr[i] = greatest;
            greatest = max(greatest, x);
        }
        return arr;
    }
};
//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/