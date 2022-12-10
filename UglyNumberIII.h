class Solution {
private: 
    const int MAX_RESULT = 2e9;

    int countUglyNumbers(long n, long a, long b, long c) {
        return (int)( n/a + n/b + n/c - n/lcm(a,b) - n/lcm(a,c) - n/lcm(b,c) + n/(lcm(a, lcm(b,c))) );
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 0, mid, right = MAX_RESULT, ugly_number = 0;    
    
        while(left <= right) {
            mid = left + (right - left) / 2;

            if(countUglyNumbers(mid, a, b, c) >= n) {
                ugly_number = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ugly_number;
    }
};
//https://leetcode.com/problems/ugly-number-iii/

/*
we can count the numbers from 1 to n that are divisible by a, b or c as follows:

n/a + n/b + n/c   							(numbers <= n that are divisible by one or more of a, b and c - may contain duplicates)
- (n/lcm(a,b) + n/lcm(a,c) + n/lcm(b,c) )	(numbers <= n that are divisible for any of the pairs of a, b or c)
+ n / lcm(a,b,c)							(numbers <= n that are divisible by all of a, b and c)

to find the n-th ugly number we do a binary search starting at [0, 2e9] and use above formula to get the result
*/