class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> compare (26, -1);
        for(int i = 0; i < s.length(); i++) {
            compare[s[i]-'a'] = i + 1 - compare[s[i]-'a'];
        }
        for(int i = 0; i < 26; i++) {
            if(compare[i] != -1 && distance[i] != compare[i]) {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.com/problems/check-distances-between-same-letters/