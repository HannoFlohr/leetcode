class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int limit = arr.size()/4, cur = arr[0], count = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == cur)
                count++;
            else {
                cur = arr[i];
                count = 1;
            }

            if(count > limit)
                break;
        }    
        return cur;
    }
};
//https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/