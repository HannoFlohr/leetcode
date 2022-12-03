class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
//https://leetcode.com/problems/longest-uncommon-subsequence-i/

/*
if length of a > length of b: no subsequence of b can be equal to A, so length of a is longest uncommon
for same lengths: only subsequence of b equal to a is b itself, so if a!=b, length of a is still the longest uncommon 
*/