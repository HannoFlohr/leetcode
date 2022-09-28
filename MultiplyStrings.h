class Solution {
public:
    string multiply(string num1, string num2) {
        string product (num1.size()+num2.size(), '0');
        int carry, x;
        
        for(int i=num1.size()-1; i>=0; i--) {
            carry = 0;
            for(int j=num2.size()-1; j>=0; j--) {
                x = (product[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                product[i+j+1] = x%10 + '0';
                carry = x/10;
            }
            product[i] += carry;
        }
        
        auto pos = product.find_first_not_of('0');
        return pos != string::npos ? product.substr(pos) : "0";
    }
};
//https://leetcode.com/problems/multiply-strings/