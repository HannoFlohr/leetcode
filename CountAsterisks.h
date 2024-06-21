class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool in_between = false;
    
        for(char c : s) {
            if(c == '|') {
                in_between = !in_between;
            }
            if(c == '*' && !in_between) {
                count++;
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/count-asterisks/