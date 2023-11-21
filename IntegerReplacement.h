class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) {
            return 0;
        }
        if(n % 2 == 0) {
            return 1 + integerReplacement(n/2);
        }
        if(n == 3) {
            return 2;
        }
        return 2 + integerReplacement( n/2 + (n%4 == 3 ? 1 : 0) );
    }
};
//https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(unsigned int n) {
        int operations = 0;

        while(n!=1) {
            if(n == 3) {
                return operations + 2;
            }
            if(n % 2 == 0) {
                n /= 2;
            } 
            else if(n % 4 == 3) {
                ++n;
            }
            else {
                --n;
            }
            ++operations;
        }

        return operations;
    }
};