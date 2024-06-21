class Solution {
public:
    int binaryGap(int n) {
        const int MAX_BIT = 31; //1e9 -> max 30th bit set
        bitset<MAX_BIT> number (n); 
        int max_distance = 0, last_set_bit = MAX_BIT;
        for(int i = 0; i < MAX_BIT; ++i) {
            if(number[i] == 0) {
                continue;
            }    
            max_distance = max(max_distance, i - last_set_bit);;
            last_set_bit = i;
        }
        return max_distance;
    }
};
//https://leetcode.com/problems/binary-gap/