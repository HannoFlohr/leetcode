class Solution {
public:
    
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        unordered_map<int, int> mp; 
        int start = 0, end = 0, count = 0;
        
        while(end < nums.size()){
            mp[nums[end]]++;
            
            while(start <= end && mp.size() > k){
                if(--mp[nums[start]] == 0) {
                    mp.erase(nums[start]);
                }
                start++;
            }
            
            count += (end-start+1);
            end++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums,k)-countSubarraysWithAtMostKDistinct(nums,k-1);
    }
};
//https://leetcode.com/problems/subarrays-with-k-different-integers/