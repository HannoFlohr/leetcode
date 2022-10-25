class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        short x, carry=0, i=num1.size()-1, j=num2.size()-1;
        
        while(i>=0 || j>=0) {
            x = 0;
            if(i>=0) x += num1[i--]-'0';    
            if(j>=0) x += num2[j--]-'0';
            x += carry;

            carry = x/10;
            x %= 10;
            
            result = to_string(x) + result;
        }
        
        if(carry>0) result = to_string(carry) + result;
        
        return result;
    }
};
//https://leetcode.com/problems/add-strings/