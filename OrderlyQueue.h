class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string result = s;
        for(size_t i=1; i<s.length(); i++)
            result = min(result, s.substr(i) + s.substr(0, i));

        return result;
    }
};
//https://leetcode.com/problems/orderly-queue/

/*
for k==1: 
whole string can be rotated by 1
return lexicographically smallest string of the possible rotations (s.length() possibilities)

for k>1:
either (1) rotate the complete string by 1 or (2) rotate only part of string except first few letters (<k) 
using (1) a letter can be rotated to the start of the string, and using (2) to the end of the string 
therefore sorted string can be created -> return sorted s
*/