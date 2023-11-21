class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_duration = 0, cur_duration, last_time = 0;
        char char_max_duration = '.';

        for(int i = 0; i < releaseTimes.size(); i++) {
            cur_duration = releaseTimes[i] - last_time; 
            if(cur_duration > max_duration || (cur_duration == max_duration && keysPressed[i] > char_max_duration)) {
                max_duration = cur_duration;
                char_max_duration = keysPressed[i];
            }
            last_time = releaseTimes[i];
        }

        return char_max_duration;
    }
};
//https://leetcode.com/problems/slowest-key/