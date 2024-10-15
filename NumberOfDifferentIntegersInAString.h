class Solution {
public:
    int numDifferentIntegers(string word) {
        const int length = word.size();
        unordered_set<string> integers {""};

        for(int start = 0, end = 0; end <= length; ++end) {
            if(end < length && isdigit(word[end]))
                start += start < end && word[start] == '0';
            else {
                integers.insert(word.substr(start, end-start));
                start = end +1;
            }
        }
        
        return integers.size() - 1;
    }
};
//https://leetcode.com/problems/number-of-different-integers-in-a-string/