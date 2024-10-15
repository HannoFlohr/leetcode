class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= accumulate(chalk.begin(), chalk.end(), 0L);
        
        for(int i = 0; i < chalk.size(); ++i) {
            if(chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};
//https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/