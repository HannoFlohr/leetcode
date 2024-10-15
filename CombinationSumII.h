class Solution {
    vector<vector<int>> result;
    
    void combine(const vector<int>& candidates, vector<int>& combination, int target, int index) {
        if(target == 0) {
            result.push_back(combination); 
            return;
        }
        
        for(int i = index; i < candidates.size(); ++i) {
            if(candidates[i] > target) {
                break; 
            }
            if(i > index && candidates[i] == candidates[i-1]) {
                continue;
            }

            combination.push_back(candidates[i]);
            combine(candidates, combination, target-candidates[i], i+1);
            combination.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        combine(candidates, combination, target, 0);
        return result;
    }
};
//https://leetcode.com/problems/combination-sum-ii/

/*
adapted approach from "Combination Sum"

if target reaches 0 save the current combination as result
else avoid candidates that are > than the remaining target and duplicate entries
than again try to recursively make valid combinations using the remaining candidates
*/