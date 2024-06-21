class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if((coordinates[0]-'a') % 2 == 0) {
            if(coordinates[1] % 2 == 0) 
                return true;
            else 
                return false;
        }
        if(coordinates[1] % 2 == 0)
            return false;
        return true;
    }
};
//https://leetcode.com/problems/determine-color-of-a-chessboard-square/