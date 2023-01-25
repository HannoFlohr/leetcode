class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;

        for(auto &c : s) {
            if(c == '1') ones++;
            else flips++;

            //flip zeros to ones or ones to zeros?
            flips = min(flips, ones); 
        }

        return flips;
    }
};
//https://leetcode.com/problems/flip-string-to-monotone-increasing/