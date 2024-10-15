class Solution {
public:
    string clearDigits(string s) {
        vector<char> chars;
        for(char c : s) {
            if(c >= '0' && c <= '9') 
                chars.pop_back();
            else
                chars.push_back(c);
        }
        return string(chars.begin(), chars.end());
    }
};
//https://leetcode.com/problems/clear-digits/