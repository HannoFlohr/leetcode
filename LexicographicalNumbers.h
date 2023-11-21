/* faster, more space */
class Solution {
private:
    void fill(int x, int n, vector<int>& nums) {
        if(x > n) {
            return;
        }
        
        nums.push_back(x);
        fill(x*10, n, nums);

        if(x % 10 != 9) {
            fill(x+1, n, nums);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        fill(1, n, nums);
        return nums;
    }
};

//https://leetcode.com/problems/lexicographical-numbers/

/* using custom compare; slower, less space

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
    vector<int> lexicalOrder(int n) {
        vector<int> nums (n);
        iota(nums.begin(), nums.end(), 1);
        sort(nums.begin(), nums.end(), lexicographicalCompare);
        return nums;
    }
};
*/