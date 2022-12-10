class Solution {
private:
    vector<vector<string>> palindrome_partitionings;
    int string_length;

    bool isPalindrome(string &s, int left, int right) {
        while(left < right) 
            if(s[left++] != s[right--])
                return false;
            
        return true;
    }

    void makePartitionings(string &s, vector<string> &partitioning, int start) {
        if(start == string_length) {
            palindrome_partitionings.push_back(partitioning);
            return;
        }

        for(int i=start; i<string_length; i++) {
            if(isPalindrome(s, start, i)) {
                partitioning.push_back(s.substr(start, i-start+1));
                makePartitionings(s, partitioning, i+1);
                partitioning.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        palindrome_partitionings.clear();
        string_length = s.size();
        vector<string> partitioning;
        makePartitionings(s, partitioning, 0);
        return palindrome_partitionings;
    }
};
//https://leetcode.com/problems/palindrome-partitioning/

/*
use backtracking approach: 
find substring from start to i that is a palindrome and add it to the "partitioning" 
then recursively process the substring (i..n) to look for other palindromes, at end of string add partitionings to the vector containing the results

then backtrack to find other possible palindromes from (start+1...n)
*/