class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;

        for(string& log : logs) {
            if(log == "../") {
                steps = max(0, steps-1);
            }
            else if(log != "./") {
                ++steps;
            }
        }

        return steps;
    }
};
//https://leetcode.com/problems/crawler-log-folder/