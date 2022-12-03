class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(auto &c : s)
            if(c == letter)
                count++;
        
        return (int)(((double)count / s.size()) * 100);
    }
};
//https://leetcode.com/problems/percentage-of-letter-in-string/