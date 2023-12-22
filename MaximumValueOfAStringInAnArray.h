class Solution {
private:
    bool isNumeric(const string& s) {
        for(char c : s) {
            if(!('0' <= c && c <= '9')) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumValue(vector<string>& strs) {
        int max_value = 0;

        for(string& s : strs) {
            if(isNumeric(s)) {
                max_value = max(max_value, stoi(s));
            }
            else {
                max_value = max(max_value, (int)s.size());
            }
        }

        return max_value;
    }
};
//https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/