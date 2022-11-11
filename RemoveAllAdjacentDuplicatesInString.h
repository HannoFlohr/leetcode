class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(auto &c : s) {
            if(result.size() && c == result.back())
                result.pop_back();
            else
                result.push_back(c);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/