class Solution {
private:
    vector<vector<int>> permutations;
    
    void makePermutation(vector<int>& nums, int start) {
        if(start >= nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        for(int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            makePermutation(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        makePermutation(nums, 0);
        return permutations;
    }
};
//https://leetcode.com/problems/permutations/

/* approach using stl algorithms

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        do {
            permutations.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return permutations;
    }
};

*/