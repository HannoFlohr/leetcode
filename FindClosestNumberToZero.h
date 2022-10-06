class Solution {
public:
    int findClosestNumber(vector<int>& nums) {  
        return *min_element(begin(nums), end(nums), [](int a, int b) {
                    return abs(a) < abs(b) || (abs(a) == abs(b) && a > b); 
                } );
    }
};
//https://leetcode.com/problems/find-closest-number-to-zero/

/*
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = INT_MAX;
        for(auto n : nums) {
            if(abs(n) < abs(result))
                result = n;
            else if(abs(n) == abs(result))
                result = max(result, n);
        }
            
        return result;
    }
};
*/