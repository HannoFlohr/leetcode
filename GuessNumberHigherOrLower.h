/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid, g;
        while(left <= right) {
            mid = (right-left) / 2 + left;
            g = guess(mid);
            if(g == 0) return mid;
            if(g == 1) left = mid+1;
            else right = mid;
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/guess-number-higher-or-lower/