class Solution {
private:
    bool isPalindrome(const string& s, int front, int back) {
        while(front < back) {
            if(s[front] != s[back]) {
                return false;
            }
            ++front;
            --back;
        }
        return true;
    }

    void findPalindromes(const string& s, int start, vector<string>& current, vector<vector<string>>& palindromes) {
        if(start == s.size()) {
            palindromes.push_back(current);
            return;
        }

        for(int end = start+1; end <= s.size(); ++end) {
            if(isPalindrome(s, start, end-1)) {
                current.push_back(s.substr(start, end-start));
                findPalindromes(s, end, current, palindromes);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<string> current;
        findPalindromes(s, 0, current, palindromes);
        return palindromes;
    }
};
//https://leetcode.com/problems/palindrome-partitioning/

/*
use backtracking approach: 
find substring from start to i that is a palindrome and add it to the "partitioning" 
then recursively process the substring (i..n) to look for other palindromes, at end of string add partitionings to the vector containing the results

then backtrack to find other possible palindromes from (start+1...n)
*/