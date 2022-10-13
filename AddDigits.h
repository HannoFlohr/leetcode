class Solution {
public:
    int addDigits(int num) {
        if(num==0)  return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};
//https://leetcode.com/problems/add-digits/

/*
https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
for base b=10 the digit root of an integer is
- 0 			if n==0
- b-1 			if n!=0 and n%(b-1)==0
- n mod (b-1)	if n%(b-1)!=0


another simpler approach below:
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int x=0;
            while(num) {
                x += num % 10;
                num /= 10;
            }
            num = x;
        }
        
        return num;
    }
};
*/