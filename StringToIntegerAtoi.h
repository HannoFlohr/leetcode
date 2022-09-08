class Solution {
public:
    int myAtoi(string s) {      
        long result = 0;
        short indicator = 1;
        short i = s.find_first_not_of(' ');
    
        if(i==-1) return 0;
        
        if(s[i]=='-' || s[i]=='+') 
            if(s[i++]=='-') 
                indicator = -1;

        while('0'<=s[i] && s[i]<='9') {
            result = result * 10 + (s[i++] - '0');
            if(result * indicator >= INT_MAX) return INT_MAX;
            if(result * indicator <= INT_MIN) return INT_MIN;
        }
        
        return result * indicator;
    }
};
//https://leetcode.com/problems/string-to-integer-atoi/