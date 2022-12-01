class Solution {
private:
    const string HEX = "0123456789abcdef";
    
public:
    string toHex(int num) {
        if(num == 0) return "0";
        
        string hex_num;
        int count = 0; 
        
        while(num && count++ < 8) {
            hex_num = HEX[(num & 0xf)] + hex_num;
            num >>= 4;
        }
        return hex_num;
    }
};
//https://leetcode.com/problems/convert-a-number-to-hexadecimal/