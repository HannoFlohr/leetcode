class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int steps = max(abs(sx-fx), abs(sy-fy));
        if(steps > 0) 
            return t >= steps;
        return t != 1;
    }
};
//https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

/* first approach

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff_x = abs(sx-fx);
        int diff_y = abs(sy-fy);
        int steps = min(diff_x, diff_y); 
        
        diff_x -= steps;
        diff_y -= steps;
        steps += diff_x + diff_y; 
        
        if(steps == 0) {
            return t == 1 ? false : true;
        }
        
        return steps <= t;
    }
};

*/