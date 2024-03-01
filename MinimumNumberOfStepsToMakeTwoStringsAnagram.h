class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> chars;
        for(char c : s) 
            chars[c]++;
        for(char c : t)
            chars[c]--;

        int steps = 0;
        for(auto i : chars) {
            if(i.second < 0)
                steps += i.second;
        }

        return abs(steps);
    }
};
//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/