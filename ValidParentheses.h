class Solution {
public:
    bool isValid(string s) {
        stack<char> stored; 
        
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') 
                stored.push(c);
            else {
                if(stored.empty() || (c==')' && stored.top()!='(') || (c=='}' && stored.top()!='{') || (c==']' && stored.top()!='[') )
                    return false;
                
                stored.pop();
            } 
        }
        
        return stored.empty();
    }
};
//https://leetcode.com/problems/valid-parentheses/