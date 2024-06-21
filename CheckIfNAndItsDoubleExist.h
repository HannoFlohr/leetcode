class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> numbers;
        for(int num : arr) {
            if((numbers.find(num*2) != numbers.end()) || (num % 2 == 0 && numbers.find(num/2) != numbers.end())) {
                return true;
            }
            numbers.insert(num);
        }
        return false;
    }
};
//https://leetcode.com/problems/check-if-n-and-its-double-exist/