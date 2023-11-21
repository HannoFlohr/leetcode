class Solution {
private:
    const int MOD = 1337;

    int powerMod(int a, int b) {
        int result = 1;
        a %= MOD;
        for(int i = 0; i < b; ++i) {
            result = (result * a) % MOD;
        }
        return result;
    }

public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) {
            return 1; 
        }
        int last_digit = b.back();
        b.pop_back();
        return powerMod(superPow(a,b), 10) * powerMod(a, last_digit) % MOD;
    }
};
//https://leetcode.com/problems/super-pow/