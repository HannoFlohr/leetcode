class Solution {
public:
    int minOperations(int n) {
        int operations = 0, x = 1;

        while(x < n) {
            operations += n - x;
            x += 2;
        }

        return operations;
    }
};
//https://leetcode.com/problems/minimum-operations-to-make-array-equal/

/*math solution
class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};
*/


/* first approach
class Solution {
public:
    int minOperations(int n) {
        int sum = 0, x = -1;
        for(int i = 0; i < n; ++i) {
            x += 2;
            sum += x;
        }

        int average = sum/n, operations = 0;
        x = -1;
        for(int i = 0; i < n; ++i) {
            x += 2;
            operations += abs(x - average);
        }

        return operations/2;
    }
};
*/