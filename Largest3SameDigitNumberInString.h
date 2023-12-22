class Solution {
public:
    string largestGoodInteger(string num) {
        string largest = "";
        
        for(int i = 0; i < num.length()-2; i++) {
            if(num[i] == num[i+1] && num[i] == num[i+2]) {
                largest = max(largest, num.substr(i,3));
            }
        }

        return largest;
    }
};
//https://leetcode.com/problems/largest-3-same-digit-number-in-string/