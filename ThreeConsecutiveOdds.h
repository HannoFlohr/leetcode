class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cur_streak = 0;
        for(auto &n : arr) {
            if(n % 2 == 1) {
                cur_streak++;
                if(cur_streak == 3)
                    return true;
            }
            else
                cur_streak = 0;
        }

        return false;
    }
};
//https://leetcode.com/problems/three-consecutive-odds/