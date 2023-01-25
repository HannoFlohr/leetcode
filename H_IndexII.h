class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;

        int n = citations.size(), left = 0, mid, right = n-1, h_index = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(citations[mid] >= n-mid) {
                h_index = n - mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return h_index;
    }
};
//https://leetcode.com/problems/h-index-ii/