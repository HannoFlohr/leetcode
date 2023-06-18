class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int cur_pushed = 0, cur_popped = 0;

        for(const int& x : pushed) {
            pushed[cur_pushed++] = x;

            while(cur_pushed>0 && pushed[cur_pushed-1] == popped[cur_popped]) {
                ++cur_popped;
                --cur_pushed;
            }
        }

        return cur_pushed == 0;
    }
};
//https://leetcode.com/problems/validate-stack-sequences/