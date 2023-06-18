class Solution {
private:
    bool hasEqualFrequency(const string& word, int pos, vector<int>& frequency) {
        frequency[word[pos]-'a']--;
        bool equal = true, jump = false;
        int prev = 0, cur = 1;
        if(pos == 0)
            prev++, cur++;

        while(cur < word.size()) { 
            if(cur == pos) {
                cur++;
                jump = true;
                continue;
            }

            if(frequency[word[cur]-'a'] != frequency[word[prev]-'a']) {
                equal = false;
                break;
            }

            cur++;
            prev++;
            if(jump) {
                jump = false;
                prev++;
            }
        }

        frequency[word[pos]-'a']++;
        return equal;
    }

public:
    bool equalFrequency(string word) {
        vector<int> frequency (26);
        for(const auto& c : word) 
            frequency[c-'a']++; 

        for(int i = 0; i < word.size(); ++i)
            if(hasEqualFrequency(word, i, frequency))
                return true;

        return false;
    }
};
//https://leetcode.com/problems/remove-letter-to-equalize-frequency/