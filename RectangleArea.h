class Solution {
private: 
    int area(int x1, int y1, int x2, int y2) {
        return abs(x2-x1) * abs(y2-y1);
    }
public:             //   A        B        C        D        E        F        G        H
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int o_left = max(ax1,bx1);
        int o_right = max(min(ax2,bx2), o_left);
        int o_bottom = max(ay1,by1); 
        int o_top = max(min(ay2,by2), o_bottom);
        return area(ax1,ay1,ax2,ay2) + //first rectangle
               area(bx1,by1,bx2,by2) - //second rectangle
               area(o_left, o_bottom, o_right, o_top); //overlap
        
    }
};
//https://leetcode.com/problems/rectangle-area/