class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            while(first >= 10) {
                first /= 10;
            }

            for(int j = i+1; j < nums.size(); j++) {
                int second = nums[j] % 10;

                if(gcd(first,second) <= 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/number-of-beautiful-pairs/