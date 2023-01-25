class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1, last_count = 0, result = 0;

        for(size_t i=1; i<s.size(); i++) {
            if(s[i-1] == s[i]) 
                count++;
            else {
                result += min(count, last_count);
                last_count = count;
                count = 1;
            }
        }

        return result + min(count, last_count);
    }
};
//https://leetcode.com/problems/count-binary-substrings/

/*
count consecutive 0's and 1's 
for example 00011110011111 -> 3 4 2 5 

number of valid substring with consecutively grouped 0's and 1's is then min(0's, 1's)
for example 0001111 -> valid: "01" "0011" "000111" -> min(3, 4)
*/