class Solution {
public:
    string reverseWords(string s) {
        string x, result = "";
        stringstream ss (s);
        
        while(getline(ss, x, ' ')) {
            reverse(x.begin(), x.end());
            result += x + ' ';
        }
        
        return result.substr(0, result.size()-1);
    }
};
//https://leetcode.com/problems/reverse-words-in-a-string-iii/