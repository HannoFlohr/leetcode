class Solution {
public:
    string generateTheString(int n) {
        string result (n, 'x');
        if(n % 2 == 0) 
            result.back() = 'y';
        return result;
    }
};
//https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

/*
class Solution {
public:
    string generateTheString(int n) {
        return (n % 2 == 1) ? string(n, 'x') : "a" + string(n-1, 'x');
    }
};
*/