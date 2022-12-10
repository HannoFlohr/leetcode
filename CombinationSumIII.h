class Solution {
private:
    vector<vector<int>> _results; 
    int _k;

    void combine(vector<int> combination, int target) {
        if(combination.size() == _k) {
            if(target == 0)
                _results.push_back(combination);
            return;
        }

        for(int i=combination.empty() ? 1 : combination.back()+1; i <= 9; i++) {
            if(target-i < 0) break;

            combination.push_back(i);
            combine(combination, target-i);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        _results.clear();
        _k = k;

        vector<int> combination;
        combine(combination, n);

        return _results;
    }
};
//https://leetcode.com/problems/combination-sum-iii/