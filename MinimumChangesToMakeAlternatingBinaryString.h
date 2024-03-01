class Solution {
public:
    int minOperations(string s) {
        int odd_ones = 0, odd_zeros = 0, even_ones = 0, even_zeros = 0;
        
        for(int i = 0; i < s.length(); i++) { 
            if(i%2==0) {
                (s[i] == '0') ? even_zeros++ : even_ones++;
            }
            else {
                (s[i] == '0') ? odd_zeros++ : odd_ones++;
            }
        }
        
        if(even_zeros+odd_ones > even_ones+odd_zeros)
            return s.length()-even_zeros-odd_ones;
        return s.length()-even_ones-odd_zeros;
    }
};
//https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/