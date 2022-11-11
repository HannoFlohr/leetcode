class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        
        //check and skip if signed number at start
        if(s[i] == '+' || s[i] == '-') i++;
        
        //check digits and points - at least one digit needed and at most one point allowed
        int digits=0, points=0;
        for( ; (s[i] >= '0' && s[i] <= '9') || s[i]=='.'; i++)
            s[i] == '.' ? points++ : digits++;
        if(digits < 1 || points > 1) 
            return false;
        
        //check exponent
        if(s[i] == 'e' || s[i] == 'E') {
            i++;
            //check and skip if signed after e/E
            if(s[i] == '+' || s[i] == '-') i++;
            
            //check digits after e/E
            digits = 0;
            for( ; s[i] >= '0' && s[i] <= '9'; i++, digits++) {}
            if(!digits) return false;
        }
        
        
        return i == s.size();
    }
};
//https://leetcode.com/problems/valid-number/