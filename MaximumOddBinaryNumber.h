class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i = 0, ones = count(s.begin(), s.end(), '1');
        string result (s.size(), '0');
        result[result.size()-1] = '1';
        ones--;
        while(ones--) {
            result[i] = '1';
            i++;
        }
        return result;
    }
};
//https://leetcode.com/problems/maximum-odd-binary-number/