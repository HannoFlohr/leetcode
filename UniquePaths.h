class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        
        m--;
        n--;
        if(m < n) swap(m, n);
        
        long combinations = 1;
        for(int i=m+1, j=1; i<=m+n; i++, j++) {
            combinations *= i;
            combinations /= j;
        }
        
        return (int)combinations;
    }
};
//https://leetcode.com/problems/unique-paths/

/*
Combinatorics problem: robot has to make m-1 steps down and n-1 steps right
and can do so in different order of combinations
-> number of combinations = ((m-1)+(n-1))! / ((m-1)! * (n-1)!)
*/