class Solution {
public:
    bool rotateString(string s, string goal) {
        int start_index = 0, length = s.length();
        bool is_shifted_string;

        while(start_index < length) {
            while(start_index < length && s[start_index] != goal[0])
                start_index++;
            
            is_shifted_string = true;
            for(int i=0; i<length; i++) {
                if(s[(start_index + i) % length] != goal[i]) {
                    is_shifted_string = false;
                    break;
                }
            }

            if(is_shifted_string) return true;

            start_index++;
        }

        return false;
    }
};
//https://leetcode.com/problems/rotate-string/


class Solution {
public:
	bool rotateString(string s, string goal) {                
		return s.size() == goal.size() && (s + s).find(goal) != string::npos;
	}
};