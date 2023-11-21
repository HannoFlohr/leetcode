class Solution {
private:
    int reverse(int num) {
        int rev = 0;
        while(num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }  
        return rev;  
    }

public:
    int countNicePairs(vector<int>& nums) {
        int count = 0, MOD = 1e9+7;
        unordered_map<int,int> freq;

        for(int num : nums) {
            count += freq[num - reverse(num)]++;
            count %= MOD;
        }

        return count;
    }
};
//https://leetcode.com/problems/count-nice-pairs-in-an-array/

/*
a[i] + reverse(a[j]) == a[j] + reverse(a[i])
a[i] - reverse(a[i]) == a[j] - reverse(a[j])

loop through all numbers and add to count if other number(s) with the same "a[i] - reverse(a[i])" were found before
*/