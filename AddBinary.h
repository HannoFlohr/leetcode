class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int ai = a.size()-1, bi = b.size()-1, carry = 0;
        
        while(ai>=0 || bi>=0 || carry==1) {
            carry += ai >= 0 ? a[ai--]-'0' : 0;
            carry += bi >= 0 ? b[bi--]-'0' : 0;
            
            result = char(carry%2 + '0') + result;
            carry /= 2;
        }
        return result;
    }
};
//https://leetcode.com/problems/add-binary/
