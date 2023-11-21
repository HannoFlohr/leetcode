class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
    
        for(int i = 1; i <= 8; ++i) {
            int cur = i;
            for(int j = i+1; j <= 9; ++j) {
                cur = cur * 10 + j;
                if(cur >= low && cur <= high) {
                    result.push_back(cur);
                }
                if(cur > high) {
                    break;
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
//https://leetcode.com/problems/sequential-digits/