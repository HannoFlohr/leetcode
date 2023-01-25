class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(numerator == 0) return "0";

        string result;
        
        if(numerator < 0 ^ denominator < 0)
            result += "-";
        
        numerator = abs(numerator);
        denominator = abs(denominator);

        result += to_string(numerator/denominator);

        if(numerator % denominator == 0) //no fractional part
            return result;

        result += ".";

        unordered_map<int,int> encountered_remainders;
        //divison process
        for(long remainder = numerator % denominator; remainder; remainder %= denominator) {
            if(encountered_remainders.find(remainder) != encountered_remainders.end()) {
                result.insert(encountered_remainders[remainder], 1, '(');
                result += ')';
                break;
            }
            //save position where remainder is first encountered
            encountered_remainders[remainder] = result.size();

            remainder *= 10;

            result += to_string(remainder / denominator);
        }
    
        return result;
    }
};
//https://leetcode.com/problems/fraction-to-recurring-decimal/