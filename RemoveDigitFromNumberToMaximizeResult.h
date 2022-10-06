class Solution {
public:
    string removeDigit(string number, char digit) {
        string result = "", current;
        for(int i=0; i<number.size(); i++) {
            if(number[i] != digit) continue;
            
            current = number.substr(0,i) + number.substr(i+1);
            result = max(result, current);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/