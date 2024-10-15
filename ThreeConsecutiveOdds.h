class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size() && count < 3; ++i) {
            if(arr[i] % 2 == 1) {
                ++count;
            }
            else {
                count = 0;
            }
        }

        return count == 3; 
    }
};
//https://leetcode.com/problems/three-consecutive-odds/