class Solution {
    
unordered_map<char,int> values { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    
public:
    int romanToInt(string s) {
        int number = 0;
        for(int i=0; i<s.size(); i++) {
            if(i<s.size()-1 && values[ s[i+1] ] > values[ s[i] ] ) {
                number += values[ s[i+1] ] - values[ s[i] ];
                i++;
            }
            else
                number += values[ s[i] ];
        }
    
        return number;
    }
};
//https://leetcode.com/problems/roman-to-integer/