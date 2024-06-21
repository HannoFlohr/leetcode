class Solution {
public:
    int numSteps(string s) {
        int steps = s.size()-1, carry = 0;

        for(int i = s.size()-1; i > 0; --i) {
            if(s[i]-'0' + carry == 1) {
                ++steps;
                carry = 1;
            }
        }
        
        return steps + carry;
    }
};
//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

/* brute force; 41/73 TC passed; 

class Solution {
public:
    int numSteps(string s) {
        unsigned long long number = 0;
        for(int i = 0; i < s.size(); ++i) {
            number = number * 2 + s[i]-'0';
        }

        int steps = 0;
        while(number != 1) {
            if(number % 2 == 0) 
                number /= 2;
            else
                ++number; 
            
            ++steps;
        }
        
        return steps;
    }
};

*/