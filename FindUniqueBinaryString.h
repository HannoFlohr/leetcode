class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i][i] == '0' ? '1' : '0';
        }
        return s;
    }
};
//https://leetcode.com/problems/find-unique-binary-string/

//https://en.wikipedia.org/wiki/Cantor%27s_diagonal_argument