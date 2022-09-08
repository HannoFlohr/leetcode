class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0; 
        
        const int n = nums.size();
        int a, b, c, sum, closest_sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for(a=0; a<n-2; a++) {
            if(a > 0 && nums[a] == nums[a-1]) continue;
            
            b = a+1;
            c = n-1;
            
            while(b < c) {
                sum = nums[a] + nums[b] + nums[c];
                
                if(sum == target) return sum;
                
                if(abs(target-sum) < abs(target-closest_sum)) 
                    closest_sum = sum;
                
                if(sum > target) c--;
                else b++;
            }
        }
        
        return closest_sum;
    }
};
//https://leetcode.com/problems/3sum-closest/