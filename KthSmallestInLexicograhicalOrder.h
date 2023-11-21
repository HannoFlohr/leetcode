class Solution {
public:
    int findKthNumber(int n, int k) {
        --k;
        int number = 1;

        while(k > 0) {
            int steps = 0; 
            long long left = static_cast<long long>(number);
            long long right = left+1;

            //calculate number of steps needed to move from current number to the next in lexicographical order
            while(left <= n) {
                steps += min(static_cast<long long>(n+1), right) - left;
                left *= 10;
                right *= 10;
            }

            //move to the right number if we need less steps than the remaining k
            if(k >= steps) {
                ++number;
                k -= steps;
            }
            //move to left number otherwise
            else {
                number *= 10;
                --k;
            }
        }

        return number;
    }
};
//https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

/* using a custom compare method; too slow for higher n

class Solution {
private:
    static bool lexicographicalCompare(int a, int b) {
        if(a == b) {
            return false;
        }
        
        const int a_digits = (a == 0 ? 1 : ceil(log(a+1)/log(10)));
        const int b_digits = (b == 0 ? 1 : ceil(log(b+1)/log(10))); 
        const int max_pos = max(a_digits, b_digits);

        for(int pos = 0; pos < max_pos; ++pos) {
            if(a_digits - pos == 0) {
                return true;
            }
            else if(b_digits - pos == 0) {
                return false;
            }
            else {
                const int a_x = (a / (int)pow(10, a_digits-1-pos)) % 10;
                const int b_x = (b / (int)pow(10, b_digits-1-pos)) % 10;

                if(a_x < b_x) {
                    return true;
                }
                else if(b_x < a_x) {
                    return false;
                }
            }
        }

        assert("Shouldnt reach this point ever");
        return false;
    }
public:
    int findKthNumber(int n, int k) {
        vector<int> nums (n);
        iota(nums.begin(), nums.end(), 1);
        sort(nums.begin(), nums.end(), lexicographicalCompare);
        return nums[k-1];
    }
};
*/