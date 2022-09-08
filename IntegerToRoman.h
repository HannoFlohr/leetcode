class Solution {

const vector<unsigned> valuesStep = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const vector<string> symbolsStep =  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
public:
    string intToRoman(int num) {
        string roman = "";
        int i=0;
        
        while(num>0 && i<valuesStep.size()) {
            while(valuesStep[i] <= num) {
                roman += symbolsStep[i];
                num -= valuesStep[i];
            }
            i++;
        }
        
        return roman;
    }
};
//https://leetcode.com/problems/integer-to-roman/