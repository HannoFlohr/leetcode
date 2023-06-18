class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isNegative = false;
        for(const auto& num : nums) {
            if(num == 0)
                return 0;
            if(num < 0)
                isNegative = !isNegative;
        }

        return isNegative ? -1 : 1;
    }
};
//https://leetcode.com/problems/sign-of-the-product-of-an-array/