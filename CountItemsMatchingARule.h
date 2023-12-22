class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;

        for(vector<string>& item : items) {
            int x = (ruleKey == "type") ? 0 : (ruleKey == "color" ? 1 : 2);
            if(item[x] == ruleValue)
                count++;
        }

        return count;
    }
};
//https://leetcode.com/problems/count-items-matching-a-rule/