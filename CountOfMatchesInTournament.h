class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};
//https://leetcode.com/problems/count-of-matches-in-tournament/

/* 
approach without doing the math below:

class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1) return 0;
        if(n&1) return 1 + numberOfMatches(n-1);
        else return n/2 + numberOfMatches(n/2);
    }
};

*/