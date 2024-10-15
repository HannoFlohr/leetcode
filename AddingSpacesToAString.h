class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if(j < spaces.size() && i == spaces[j]) {
                result += ' ';
                ++j;
            }
            result += s[i];
        }
        return result;
    }
};
//https://leetcode.com/problems/adding-spaces-to-a-string/