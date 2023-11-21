class Solution {
public:
    string truncateSentence(string s, int k) {
        size_t pos = 0;

        while(pos < s.length() && k > 0) 
            if(s[pos++] == ' ')
                --k;

        return s.substr(0, pos-(pos < s.length()) );
    }
};
//https://leetcode.com/problems/truncate-sentence/