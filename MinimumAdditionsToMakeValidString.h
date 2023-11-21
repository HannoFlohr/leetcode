class Solution {
public:
    int addMinimum(string word) {
        int count = 0, i = 0;

        while(i < word.length()) { 
            word[i] == 'a' ? i++ : count++;
            word[i] == 'b' ? i++ : count++;
            word[i] == 'c' ? i++ : count++;
        }
        
        return count;
    }
};
//https://leetcode.com/problems/minimum-additions-to-make-valid-string/