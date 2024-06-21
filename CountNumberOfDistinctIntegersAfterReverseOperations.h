class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> distinct_numbers;

        for(int num : nums) { 
            distinct_numbers.insert(num);
            
            int reversed = 0;
            while(num > 0) {
                reversed = reversed * 10 + (num%10);
                num /= 10;
            } 
            
            distinct_numbers.insert(reversed);
        }

        return distinct_numbers.size();
    }
};
//https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/