class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string cur;
        
        for(char &c : s) {
            if(c != ' ') 
                cur += c;
            else if(cur != "") {
                words.push(cur);
                cur = "";
            }
        }
        
        if(cur != "") words.push(cur);
        cur = "";
        
        while(!words.empty()) {
            cur += words.top();
            if(words.size() > 1) cur += " ";
            words.pop(); 
        }
        
        return cur;
    }
};
//https://leetcode.com/problems/reverse-words-in-a-string/