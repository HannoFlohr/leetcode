class Solution {
private: 
    long solve(int n, int index, int a) {
        int b = max(a - index, 0);
        long result = long(a+b) * (a-b+1) / 2;

        b = max(a - ((n-1)-index), 0);
        result += long(a+b) * (a-b+1) / 2;

        return result - a;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;

        while(left < right) {
            mid =  (left + right + 1) / 2;
            if( solve(n, index, mid) <= maxSum )
                left = mid;
            else
                right = mid - 1;
        }

        return left + 1;
    }
};
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/