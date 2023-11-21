class Solution {

public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacci_numbers (2, 1);
        int min_number_for_sum_0 = 0;

        for(int i = 2; fibonacci_numbers.back() < k; i++) {
            fibonacci_numbers.push_back(fibonacci_numbers[i-2] + fibonacci_numbers[i-1]);
        }

        for(int i = fibonacci_numbers.size()-1; i >= 0; i--) {
            if(fibonacci_numbers[i] > k) {
                continue;
            }
                
            min_number_for_sum_0++;
            k -= fibonacci_numbers[i];
            if(k == 0) {
                break;
            }
        }

        return min_number_for_sum_0;
    }
};
//https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/