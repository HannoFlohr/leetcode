class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.back() == '0')
            num.pop_back();
        return num;
    }
};
//https://leetcode.com/problems/remove-trailing-zeros-from-a-string/