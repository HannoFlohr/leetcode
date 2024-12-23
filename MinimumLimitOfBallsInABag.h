class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, mid, right = 1e9, count;

        while(left < right) {
            mid = (left + right) / 2;
            count = 0;
            for(int n : nums)
                count += (n-1) / mid;

            if(count > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/