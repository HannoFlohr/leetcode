class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) 
            return {};

        const vector<string> buttons = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        result.push_back("");
        
        for(const char& digit : digits) {
            vector<string> cur;
            for(const char& ch : buttons[digit-'0']) 
                for(const string& r : result)
                    cur.push_back(r + ch);
            
            result = cur;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/