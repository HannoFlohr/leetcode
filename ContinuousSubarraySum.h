class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        
        unordered_map<int,int> remainder {{0,0}};
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            
            if(!remainder.count(sum % k)) 
                remainder[sum % k] = i+1;
            else if(remainder[sum % k] < i)
                return true;       
        }
        
        return false;
    }
};
//https://leetcode.com/problems/continuous-subarray-sum/

/*
subarray sum [l..r] if its multiple of k (-> sum % k == 0)

sum can be represented as nums[l]+nums[l+1]+...+nums[r] = sum[r+1] - sum[l] to find a valid solution modulo k 
from properties of modulo operations the equality (sum[r+1]-sum[l]%k) = 0 -> sum[r+1]%k = sum[l]%k 

for each index r we are only interested in indices l<r where remainder[l]%k = remainder[r+1]%k (ensuring that subarray size is >= 2)
-> use hashmap to store leftmost index for each remainder of the sum % k
*/