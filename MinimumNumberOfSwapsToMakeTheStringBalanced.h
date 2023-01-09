class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        for(auto &c : s) {
            if(c == '[')
                open++;
            else 
                if(open != 0) open--;
        }

        return (open + 1) / 2;
    }
};
//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/