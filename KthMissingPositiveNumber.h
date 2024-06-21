class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int n : arr) {
            if(n <= k) {
                ++k;
            }
        }
        return k;
    }
};
//https://leetcode.com/problems/kth-missing-positive-number/

/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last_number = 0;

        for(int cur_number : arr) { 
            int diff = cur_number - last_number - 1;
            if(diff > 0) {
                if(k <= diff) {
                    return last_number + k;
                }
                    
                k -= diff;
            }

            last_number = cur_number;
        }

        return last_number + k;
    }
};
*/