class Solution {
public:
    bool canWinNim(int n) {
        return n%4 == 0 ? false : true;
    }
};
//https://leetcode.com/problems/nim-game/