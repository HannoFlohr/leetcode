class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        
        unsigned sum = 1;
        for(int i=2; i<=sqrt(num); i++) 
            if(num%i == 0)
                sum += i + (i==num/i ? 0 : num/i);
        
        return sum == num;
    }
};
//https://leetcode.com/problems/perfect-number/

/*
above: more optimized version taking into account the perfect square rule
below: first approach

class Solution {
public:
    bool checkPerfectNumber(int num) {
        unsigned sum = 0;
        for(int i=num/2; i>0; i--) 
            if(num%i == 0)
                sum += i;
        
        return sum == num;
    }
};

with the given constraints we can see that there exist only 5 perfect numbers in the given range <= 10^8
see: https://en.wikipedia.org/wiki/List_of_Mersenne_primes_and_perfect_numbers
so a hardcoded could also be used for this example
e.g.: return ((num == 6) || (num == 28) || (num == 496) || (num == 8128) || (num == 33550336));

*/