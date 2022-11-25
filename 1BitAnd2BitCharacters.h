class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //1-bits between the two last 0-bits give the answer, odd=false, even=true
        int one_bits = 0, i = bits.size()-2;
        while(i >= 0 && bits[i--] == 1)
            one_bits++;
        return one_bits % 2 == 0;
    }
};
//https://leetcode.com/problems/1-bit-and-2-bit-characters/