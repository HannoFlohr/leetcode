class Solution {
public:
    int minimumLength(string s) {
        int start = 0, end = s.size()-1;
        char cur;

        while(start < end && s[start] == s[end]){
            cur = s[start];
            while(start < end && s[start] == cur) {
                start++;
            }
            while(start < end && s[end] == cur) {
                end--;
            }
        }

        return s[start] == cur ? 0 : end-start+1;
    }
};
//https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/