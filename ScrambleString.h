class Solution {
private:
    unordered_map<string,int> memo;
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1 == s2) 
            return true;

        if(memo.find(s1+s2) != memo.end())
            return memo[s1+s2];
        
        int length = s1.length();
        unordered_map<char,int> char_count ;
        for(auto &c : s1) 
            char_count[c]++;
        for(auto &c : s2) 
            char_count[c]--;
        for(auto &[_,count] : char_count)
            if(count != 0)
                return (memo[s1+s2] = false);

        if(length <= 3)
            return true;

        bool solutionFound = false;
        for(int i=1; i<length; ++i) {
            solutionFound = solutionFound || (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)));
            solutionFound = solutionFound || (isScramble(s1.substr(0,i), s2.substr(length-i)) && isScramble(s1.substr(i), s2.substr(0,length-i)));
            if(solutionFound)
                break;
        }

        return memo[s1+s2] = solutionFound;
    }
};
//https://leetcode.com/problems/scramble-string/