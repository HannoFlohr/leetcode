class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0, curSum=0;
        bool first = false, second = false, third = false;
        
        for(auto a:arr) sum += a;
        if(sum%3 != 0) return false;
        sum /= 3;
        
        
        for(auto a:arr) {
            curSum += a;
            if(!first && curSum == sum) first = true;
            else if(first && !second && curSum == sum*2) second = true;
            else if(second && !third && curSum == sum*3) third = true;
        }
        
        return third;
    }
};
//https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/