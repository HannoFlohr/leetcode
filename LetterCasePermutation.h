class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result, strings;
        vector<vector<char>> candidates (s.size());

        //init candidates for each position of the permutation
        for(size_t i=0; i<s.size(); i++) {
            if(!isdigit(s[i])) {
                candidates[i].push_back(tolower(s[i]));
                candidates[i].push_back(toupper(s[i]));
            }
            else
                candidates[i].push_back(s[i]);
        }

        //add first char candidates
        for(const char& c : candidates[0]) 
            result.push_back(string()+c);

        //make permutations
        for(size_t i=1; i<s.size(); i++) {
            if(isdigit(s[i])) {
                for(auto& x : result)
                    x += s[i];
            }
            else {
                strings.clear();

                for(const auto& x : result) {
                    strings.push_back(x + candidates[i][0]);
                    strings.push_back(x + candidates[i][1]);
                }

                result = strings;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/letter-case-permutation/