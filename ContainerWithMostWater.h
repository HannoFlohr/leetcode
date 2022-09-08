class Solution {
public:
    int maxArea(vector<int>& height) {
        int minHeight, maxArea = 0;
        int left = 0, right = height.size()-1;
        
        while(left < right) {
            minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, minHeight * (right-left) );
            
            while(height[left] <= minHeight && left<right)
                left++;
            while(height[right] <= minHeight && left<right)
                right--;
        }
        
        return maxArea;
    }
};
//https://leetcode.com/problems/container-with-most-water/