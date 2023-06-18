class Solution {
public:
    int flipLights(int n, int presses) {
        if(presses == 0) //no presses, no changes
            return 1;
        if(n == 1) //1 bulb, either on or off
            return 2;
        if(n == 2) //2 bulbs, with one press 3 states can be reached, all 4 with more presses
            return presses == 1 ? 3 : 4;
        if(presses == 1) //more than 2 bulbs, one press
            return 4;
        return presses == 2 ? 7 : 8;
    }
};
//https://leetcode.com/problems/bulb-switcher-ii/