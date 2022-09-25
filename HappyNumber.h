class Solution {

int squareSum(int n) {
    int sum = 0;
    while(n) {
        sum += pow(n%10, 2);
        n /= 10;
    }
    return sum;
}
    
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
        } while(slow != fast);
        
        return slow==1 ? true : false;
    }
};
//https://leetcode.com/problems/happy-number/