class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> chars;
        for(const auto& c : s)
            chars.insert(c);
        return chars.size();
    }
};
//https://leetcode.com/problems/minimize-string-length/