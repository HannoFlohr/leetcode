class Solution {
public:
    int tribonacci(int n) {
        vector<int> T = {0,1,1};
        if(n < 3) {
            return T[n];
        }
        int tri;

        for(int i = 3; i <= n; ++i) {
            tri = T[0]+T[1]+T[2];
            T[0] = T[1];
            T[1] = T[2];
            T[2] = tri; 
        }

        return T.back();
    }
};
//https://leetcode.com/problems/n-th-tribonacci-number/