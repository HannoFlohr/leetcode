class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int n = nums.size();
        
        for(int i=0; i<n; i++)
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        for(int i=0; i<n; i++)
            nums[i] /= n;
        
        return nums;
    }
};
//https://leetcode.com/problems/build-array-from-permutation/

/*
any nums[i] is between 0 .. n-1; 
b = k*n -> nums[i] + b / n = k  (b= nums[nums[i]] % k)

if we change a nums[i] we dont want it to affect the lookup of nums[nums[i]] 
c = n * (nums[nums[i]]%n)
c % n = 0 therefore: nums[i] + C % n = nums[i] 
*/