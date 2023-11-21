class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int last_moment = 0;
        for(int l : left) {
            last_moment = max(last_moment, l);
        }        
        for(int r : right) {
            last_moment = max(last_moment, n - r);
        }
        return last_moment;
    }
};
//https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/