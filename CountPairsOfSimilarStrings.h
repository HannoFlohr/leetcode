class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<vector<bool>, int> masks;

        for(string& word : words) {
            vector<bool> mask (26, false);
            for(char c : word) {
                mask[c-'a'] = true;
            }
            
            masks[mask]++;
        } 

        int pairs = 0;
        for(auto& [mask, count] : masks) {
            if(count < 2) {
                continue;
            }        
            pairs += ((count-1) * (count) / 2);
        }

        return pairs;
    }
};
//https://leetcode.com/problems/count-pairs-of-similar-strings/