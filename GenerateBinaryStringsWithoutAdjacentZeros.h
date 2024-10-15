class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> strings = {"0", "1"};
        
        for(int length = 2; length <= n; ++length) {
            vector<string> new_strings;

            for(string& s : strings) {
                if(s.back() != '0')
                    new_strings.push_back(s + '0');
                new_strings.push_back(s + '1');
            }

            strings = new_strings;     
        }

        return strings;
    }
};
//https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/