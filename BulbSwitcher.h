class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
//https://leetcode.com/problems/bulb-switcher/

/*
bulb i end state is on if it is switched an odd number of times
bulb i is switched is in round x if x divides i 
divisors come in pairs, except for squares
so bulb i ends up on only if i is a square

amount of squares <= i determinded by sqrt(i) 
*/