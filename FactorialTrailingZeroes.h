class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for(int i=5; n / i >= 1; i*=5)
            count += n / i;
        return count;
    }
};
//https://leetcode.com/problems/factorial-trailing-zeroes/

/*
a trailing zero in n! is produced by prime factors 2 and 5
amount of factors 2 is always >= amount of factors 5
-> only need to count the 5's

count of 5's = floor(n/5) + floor(n/25) + floor(n/125) + ...
*/