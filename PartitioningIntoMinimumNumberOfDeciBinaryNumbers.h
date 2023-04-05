class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

/*
for example:
27346209830709182346
->
11111101110101111111
11111101110101011111
 1111001110101010111
 1011001100101010011
 1001001100101010001
 1001001100101010001
 1000001100101010000
	   1100001010000
	   1000001000000

we can see that the amount of deci binary numbers that are needed is equal to the highest digit in the number 
*/