class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> result (high+1);
        
        for(int i = 0; i < s.size(); ++i) {
            result[i] = (s[i] == 'I') ? low++ : high--; 
        }
        result.back() = low;

        return result;
    }
};
//https://leetcode.com/problems/di-string-match/