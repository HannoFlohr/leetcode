class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int number = 0;
        vector<bool> answer (nums.size());

        for(int i = 0; i < nums.size(); ++i) {
            number = (2*number + nums[i]) % 5;
            answer[i] = !number;
        }
        return answer;
    }
};
//https://leetcode.com/problems/binary-prefix-divisible-by-5/