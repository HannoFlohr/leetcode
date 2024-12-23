class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count (26,0);
        for(char c : s) 
            ++count[c-'a'];

        string result = "";
        while(result.size() < s.size()) {
            int i = 25;
            bool same_char = false;
            for( ; i >= 0; --i) {
                //check if last used char still available
                if(!result.empty() && i == result.back()-'a' && count[i]) {
                    same_char = true;
                    continue;
                }
                //next char with positive count found
                if(count[i])
                    break;
            }

            if(i == -1)
                break;
            int fill = same_char ? 1 : min(count[i], repeatLimit); 
            count[i] -= fill;
            result += string(fill, i+'a');
        }

        return result;
    }
};
//https://leetcode.com/problems/construct-string-with-repeat-limit/