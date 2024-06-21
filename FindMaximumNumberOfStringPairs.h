class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> memory;
        int pairs = 0;

        for(string& word : words) {
            if(memory.contains(word)) {
                ++pairs;
                continue;
            }
            
            string reversed = word;
            reverse(reversed.begin(), reversed.end());
            memory.insert(reversed);
        }

        return pairs;
    }
};
//https://leetcode.com/problems/find-maximum-number-of-string-pairs/