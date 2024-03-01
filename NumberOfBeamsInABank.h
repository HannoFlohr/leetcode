class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int devices_in_last_row = 0, beams = 0;

        for(const string& row : bank) {
            int devices_in_cur_row = 0;
            for(char c : row) {
                if(c == '1') {
                    ++devices_in_cur_row;
                }
            }
            if(devices_in_cur_row == 0) {
                continue;
            }

            beams += devices_in_cur_row * devices_in_last_row;
            devices_in_last_row = devices_in_cur_row;
        }

        return beams;
    }
};
//https://leetcode.com/problems/number-of-laser-beams-in-a-bank/