class Solution {
public:
    int pivotInteger(int n) {
        vector<int> sum (n+1, 0);
        for(int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + i;
        }

        int sum_back = 0;
        for(int i = n; i > 0; --i) {
            sum_back += i; 
            if(sum_back == sum[i]) {
                return i;
            }
        } 
 
        return -1;
    }
};
//https://leetcode.com/problems/find-the-pivot-integer/

/* using math properties:

int pivotInteger(int n) {
    int sum = n * (n + 1) / 2, x = sqrt(sum);
    return x * x == sum ? x : -1;
}

*/