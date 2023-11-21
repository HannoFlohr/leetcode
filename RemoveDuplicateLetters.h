class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> char_frequency (26, 0);
        vector<bool> in_stack (26, false);
        stack<int> saved_chars;

        for(char c : s) 
            char_frequency[c-'a']++;

        for(int i = 0; i < s.length(); ++i) {
            char_frequency[s[i]-'a']--;

            if(in_stack[s[i]-'a'] == true) {
                continue;
            }

            //if char c at top of stack is smaller than the current char, and there is still another c after the current index
            //we can pop that c from the stack
            while(!saved_chars.empty() && s[i] < s[saved_chars.top()] && char_frequency[s[saved_chars.top()]-'a'] > 0) {
                in_stack[s[saved_chars.top()]-'a'] = false;
                saved_chars.pop();
            }

            saved_chars.push(i);
            in_stack[s[i]-'a'] = true;
        } 

        string result;
        while(!saved_chars.empty()) {
            result = s[saved_chars.top()] + result;
            saved_chars.pop();
        }

        return result;
    }
};
//https://leetcode.com/problems/remove-duplicate-letters/