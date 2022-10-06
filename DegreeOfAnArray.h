class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq, first;
        int result=0, maxdegree=0;
        
        for(int i=0; i<nums.size(); i++) {
            if(first.count(nums[i]) == 0) 
                first[nums[i]] = i;
            
            if(++freq[nums[i]] > maxdegree) {
                maxdegree = freq[nums[i]];
                result = i - first[nums[i]] + 1; 
            }
            else if(freq[nums[i]] == maxdegree)
                result = min(result, i - first[nums[i]] + 1);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/degree-of-an-array/