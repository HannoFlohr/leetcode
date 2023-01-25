class Solution {
public:
    bool digitCount(string num) {
        vector<int> digit_frequency(10, 0);
        for(auto &c : num) 
            digit_frequency[c-'0']++;

        for(int i=0; i<num.size(); i++)
            if(num[i]-'0' != digit_frequency[i])
                return false;

        return true;
    }
};
//https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/