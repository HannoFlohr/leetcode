class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int black = 0;

        for(char c : s) {
            if(c == '1')
                ++black;
            else 
                steps += black;
        }

        return steps;
    }
};
//https://leetcode.com/problems/separate-black-and-white-balls/