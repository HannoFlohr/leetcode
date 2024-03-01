class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> chars;
        for(string& word : words) {
            for(char c : word) {
                chars[c]++;
            }
        }

        for(auto& [_,freq] : chars) {
            if(freq%n != 0)
                return false;
        }

        return true;
    }
};
//https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/