class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0; 
        int index, bitmask = 0;
        unordered_map<int,int> bitmask_count;
        bitmask_count[bitmask]++;

        for(char c : word) {
            //update bitmask according to index of currenct char
            index = c-'a';
            bitmask ^= 1 << index;
            //increase count using saved bitmask count
            count += bitmask_count[bitmask];
            for(int i = 0; i < 10; ++i) {
                count += bitmask_count[bitmask ^ (1 << i)];
            }
            //increment for current bitmask
            bitmask_count[bitmask]++;
        }

        return count;
    }
};
//https://leetcode.com/problems/number-of-wonderful-substrings/

/* brute force; 70/88 testcases passed

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;

        for(int start = 0; start < word.size(); ++start) {
            vector<int> chars_in_substring (26, 0);
            int even = 0, odd = 0, c;
            
            for(int end = start; end < word.size(); ++end) {
                c = word[end]-'a';
                if(++chars_in_substring[c] % 2 == 0) {
                    ++even; 
                    --odd;
                }
                else {
                    ++odd;
                    if(chars_in_substring[c] != 1) {
                        --even;
                    }
                }

                if(odd < 2) {
                    ++count;
                }
            }
        }

        return count;
    }
};

*/