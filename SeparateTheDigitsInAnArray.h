class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits, cur;

        for(int num : nums) {
            while(num > 0) {
                cur.push_back(num%10);
                num /= 10;
            }

            for(auto it = cur.rbegin(); it != cur.rend(); it++) {
                digits.push_back(*it);
            }
            cur.clear();
        }

        return digits;
    }
};
https://leetcode.com/problems/separate-the-digits-in-an-array/