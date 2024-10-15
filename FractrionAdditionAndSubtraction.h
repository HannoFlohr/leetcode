class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1, cur_num, cur_den;
        char slash;
        istringstream iss (expression);

        while(iss >> cur_num >> slash >> cur_den) {
            // sum of fraction a/b and c/d = (a*d + c*b) / b*d      
            numerator = numerator * cur_den + cur_num * denominator;
            denominator *= cur_den;

            //cancel out the greatest common divisor
            int gcd = abs(__gcd(numerator, denominator));
            numerator /= gcd;
            denominator /= gcd;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
//https://leetcode.com/problems/fraction-addition-and-subtraction/