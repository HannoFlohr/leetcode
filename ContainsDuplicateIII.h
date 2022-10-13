class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++) {
            int n = nums[i] / ((long)valueDiff+1);
            if(nums[i] < 0) n--;
            
            if(m.find(n) != m.end())
                return true;
            else {
                m[n] = nums[i];
                if(m.find(n-1) != m.end() && (long)nums[i] - m[n-1] <= valueDiff) return true;
                if(m.find(n+1) != m.end() && (long)m[n+1] - nums[i] <= valueDiff) return true;
                
                if(m.size() > indexDiff) {
                    int remove = nums[i-indexDiff] / ((long)valueDiff+1);
                    if(nums[i-indexDiff] < 0) remove--;
                    m.erase(remove);
                }
            }
        }
        
        return false;
    }
};
//https://leetcode.com/problems/contains-duplicate-iii/