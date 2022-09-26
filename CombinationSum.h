class Solution {
private:
    vector<vector<int>> result;
    
    void combine(const vector<int>& candidates, const int& target, vector<int>& combination, int sum, int index) {
        if(sum > target) return;
        
        if(sum == target) {
            result.push_back(combination); 
            return;
        }
        
        for(int i=index; i<candidates.size(); i++) {
            combination.push_back(candidates[i]);
            combine(candidates, target, combination, sum+candidates[i], i);
            combination.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        combine(candidates, target, combination, 0, 0);
        return result;
    }
};
//https://leetcode.com/problems/combination-sum/

/*
backtracking approach
loop through "all" candidate combinations
if sum is greater than the target we can backtrack as adding more will not give valid results
if sum is equal to target we store the current combination as a result
else we recursively try to make new valid combinations with the remaining candidates 

(could be further improved by removing 'sum' from the combine method, and instead 
subtracting from 'target' and comparing that to 0 and few other changes accordingly) 
*/