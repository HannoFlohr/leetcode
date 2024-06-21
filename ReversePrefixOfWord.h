class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start = 0, end = word.find(ch);
        if(end != -1) {
            while(start < end) {
                swap(word[start], word[end]);
                ++start;
                --end;
            }
        }
        return word;
    }
};
//https://leetcode.com/problems/reverse-prefix-of-word/
