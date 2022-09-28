class Solution {
private:
    vector<vector<int>> permutations;
    
    void makePermutation(vector<int>& nums, int start) {
        if(start == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        for(int i=start; i<nums.size(); i++) {
            if(i != start && nums[i] == nums[start]) continue;
            
            swap(nums[start], nums[i]);
            makePermutation(nums, start+1);
        }
        
        for(int i=nums.size()-1; i>start; i--)
            swap(nums[start], nums[i]);
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        makePermutation(nums, 0);
        return permutations;
    }
};
//

/* adapted approach from "Permutations"; below: first approach using a set than sorting out duplicates (a lot slower) 

class Solution {
private:
    set<vector<int>> permutations;
    
    void makePermutation(vector<int>& nums, int start) {
        if(start >= nums.size()) {
            permutations.insert(nums);
            return;
        }
        
        for(int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            makePermutation(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        makePermutation(nums, 0);
        
        vector<vector<int>> p;
        for(auto x:permutations) p.push_back(x);
        return p;
    }
};

*/