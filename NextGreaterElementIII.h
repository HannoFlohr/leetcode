class Solution {
public:
    int nextGreaterElement(int n) {
        string number = to_string(n);
        next_permutation(number.begin(), number.end());
        long result = stol(number);
        
        return (result > INT_MAX || result <= n) ? -1 : (int)result;
    }
};
//https://leetcode.com/problems/next-greater-element-iii/