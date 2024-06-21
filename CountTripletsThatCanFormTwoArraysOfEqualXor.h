class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), xor_a, xor_b, count = 0;

        for(int first = 0; first < n; ++first) {
            xor_a = 0;
            for(int second = first+1; second < n; ++second) {
                xor_a ^= arr[second-1];
                xor_b = 0;
                for(int third = second; third < n; ++third) {
                    xor_b ^= arr[third];
                    if(xor_a == xor_b) {
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
};
//https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/