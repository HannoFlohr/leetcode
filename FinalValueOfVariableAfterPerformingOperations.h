class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for(const string& op : operations) {
            if(op[1] == '+') {
                ++x;
            }
            else
                --x;
        }

        return x;    
    }
};
//https://leetcode.com/problems/final-value-of-variable-after-performing-operations/