class Solution {
public:
    int numberOfChild(int n, int k) {
        --n;
        int rounds = k / n;
        k %= n;
        return (rounds % 2 == 0) ? k : n-k;
    }
};
//https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/

/*
class Solution {
public:
    int numberOfChild(int n, int k) {
        --n;
        return ((k/n) % 2 == 0) ? (k%n) : n-(k%n);
    }
};
*/