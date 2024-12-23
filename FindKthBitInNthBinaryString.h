class Solution {
public:
    char findKthBit(int n, int k) {
        //base case
        if(n == 1)
            return '0';
        
        //middle position of nth binary string
        int length = (1<<n) - 1, middle = length / 2 + 1;

        //k is at middle
        if(k == middle) 
            return '1';
        //k is in first half of nth binary string
        if(k < middle)
            return findKthBit(n-1, k);
        //k is in second half of nth binary string
        return findKthBit(n-1, length-k+1) == '0' ? '1' : '0';
    }
};
//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/