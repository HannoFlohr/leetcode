class Solution {
public:
    int convertTime(string current, string correct) {
        int start_hour = stoi(current.substr(0,2)), start_minute = stoi(current.substr(3,2));
        int end_hour = stoi(correct.substr(0,2)), end_minute = stoi(correct.substr(3,2));
        int count = 0;

        if(end_minute < start_minute) {
            ++start_hour;
        }

        int diff = (end_minute - start_minute + 60) % 60; 
        while(diff >= 15) {
            diff -= 15;
            ++count;
        }
        while(diff >= 5) {
            diff -= 5;
            ++count;
        }
        while(diff >= 1) {
            --diff;
            ++count;
        }
        
        return count + (end_hour-start_hour);
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/