class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int largest = 0, n = heights.size(), cur_height, index;
        vector<int> s; //use vector as stack
        
        for(int i=0; i<n; i++) {
            while(!s.empty() && heights[s.back()] >= heights[i]) {
                cur_height = heights[s.back()];
                s.pop_back();
                
                index = s.size() > 0 ? s.back() : -1;
                largest = max(largest, cur_height * (i-index-1) );
            }
            s.push_back(i);
        }
        
        return largest;
    }
};
//https://leetcode.com/problems/largest-rectangle-in-histogram/