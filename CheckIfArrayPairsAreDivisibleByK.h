class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> frequencies;
        int remaining;

        for(int x : arr) {
            frequencies[((x%k)+k)%k]++;
        }
        for(int x : arr) {
            remaining = ((x%k)+k)%k;
            if(remaining == 0) { 
                if(frequencies[remaining]%2 != 0) {
                    return false;
                }
            }     
            else if(frequencies[remaining] != frequencies[k-remaining]) {
                return false;
            }
        }
        
        return true;
    }
};
//https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/