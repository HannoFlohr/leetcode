class Solution {
public:
    bool detectCapitalUse(string word) {
        int count_upper = 0;
        for(char &c : word)
            if(isupper(c))
                count_upper++;
        
        return !count_upper || count_upper == word.size() || count_upper == 1 && isupper(word[0]);
    }
};
//https://leetcode.com/problems/detect-capital/