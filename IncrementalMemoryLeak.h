class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while(i < INT_MAX) {
            if(memory1 >= i && memory1 >= memory2) 
                memory1 -= i;
            else if(memory2 >= i)
                memory2 -= i;
            else
                break;

            ++i;
        }

        return {i, memory1, memory2};
    }
};
//https://leetcode.com/problems/incremental-memory-leak/