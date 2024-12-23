class Solution {
public:
    string compressedString(string word) {
        char c = '.';
        string comp = "";
        int count = 0, i = 0, n = word.size();

        while(i < n) {
            if(word[i] != c) {
                c = word[i];
                count = 1;
                continue;
            }

            while(word[++i] == c) 
                ++count;

            while(count > 0) {
                comp += (count <= 9) ? to_string(count) : "9";
                comp += c;
                count -= 9;
            }
        }

        return comp;
    }
};
//https://leetcode.com/problems/string-compression-iii/