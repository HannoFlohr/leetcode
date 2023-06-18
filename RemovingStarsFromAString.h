class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        for(const auto& c : s) {
            if(c == '*' && result.size()>0)
                result.pop_back();
            else
                result += c;
        }

        return result;
    }
};
//https://leetcode.com/problems/removing-stars-from-a-string/