class Solution {
public:
    int mySqrt(int x) {
        long int a=x;
        
        while(a*a > x)
            a = (a + x/a) / 2;
        
        return a;
    }
};
//https://leetcode.com/problems/sqrtx/

/* 
first attempt below, than used https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division 
for solution above

class Solution {
public:
    int mySqrt(int x) {
        unsigned int a=0, square=0;
        while(square <= x) {
            a++;
            square = a*a;
        } 
        return --a;
    }
};
*/