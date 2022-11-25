class Solution {
public:
    int calculate(string s) {
        int result = 0, cur;
        char c;
        vector<int> signs (2, 1);
        
        for(int i=0; i<s.size(); i++) {
            c = s[i];
            
            if(c >= '0') {
                cur = 0;
                
                while(i<s.size() && s[i]>='0')
                    cur = 10 * cur + (s[i++]-'0');
                    
                result += signs.back() * cur;
                signs.pop_back();
                i--;
            }
            else if(c == '(' && s[i+1]=='-')
                continue;
            else if( c == ')')
                signs.pop_back();
            else
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        
        return result;
    }
};
//https://leetcode.com/problems/basic-calculator/