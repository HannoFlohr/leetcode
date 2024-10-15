class Solution {
private:
    int convertNumber(const vector<int>& mapping, int n) {
        if(n == 0) {
            return mapping[0];
        }
        int number = 0;
        for(int power = 1; n > 0; power *= 10) {
            number += mapping[n%10] * power;
            n /= 10;
        }
        return number;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int,int>> numbers (n);
        //map each number and remember original index
        for(int i = 0; i < n; ++i) {
            numbers[i] = {convertNumber(mapping, nums[i]), i};
        }
        //sort mapped numbers
        sort(numbers.begin(), numbers.end());

        vector<int> sorted (n);
        for(int i = 0; i < n; ++i) {
            sorted[i] = nums[numbers[i].second];
        } 
        return sorted;
    }
};
//https://leetcode.com/problems/sort-the-jumbled-numbers/