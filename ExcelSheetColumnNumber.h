class Solution {
public:
    int titleToNumber(string columnTitle) {
        int exp = columnTitle.size()-1, result=0;
        for(const auto &c : columnTitle) 
            result += (int)(c -'A' + 1) * pow(26, exp--);

        return result;
    }
};
//https://leetcode.com/problems/excel-sheet-column-number/