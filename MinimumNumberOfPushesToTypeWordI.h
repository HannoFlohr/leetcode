class Solution {
public:
    int minimumPushes(string word) {
        int length = word.size(), multiplier = 1, pushes = 0;
        
        while(length >= 8) {
            pushes += 8 * multiplier;
            ++multiplier;
            length -= 8;
        }

        return pushes + length * multiplier;
    }
};
//https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/