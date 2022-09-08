class Solution {

const vector<string> buttons = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        vector<string> result;
        result.push_back("");
        
        for(auto d : digits) {
            vector<string> cur;
            for(auto c : buttons[d-'0']) 
                for(auto r : result)
                    cur.push_back(r + c);
            
            result.swap(cur);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/