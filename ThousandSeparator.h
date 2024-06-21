class Solution {

public:
    string thousandSeparator(int n) {
        string result = "", number = to_string(n);
        const int nsize = number.size();

        for(int i = 0; i < nsize; ++i) {
            if(i > 0 && (nsize - i) % 3 == 0) {
                result += '.';
            }
            result += number[i];
        }

        return result;
    }
};
//https://leetcode.com/problems/thousand-separator/