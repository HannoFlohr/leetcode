class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> banned_numbers (banned.begin(), banned.end());
        int count = 0, sum = 0;

        for(int i = 1; i <= n; ++i) {
            if(banned_numbers.contains(i))
                continue;
            if(sum + i > maxSum)
                break;
            
            sum += i;
            ++count;
        }

        return count;
    }
};
//https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/