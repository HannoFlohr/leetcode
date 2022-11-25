class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string,int> differences;
        unordered_map<string,string> differenceToWord;
        string cur;
        int value;
        
        for(string &word : words) {
            cur = "";
            for(int i=1; i<word.size(); i++) {
                value = word[i] - word[i-1];
                cur += to_string(value) + ",";
            }
            differences[cur]++;
            differenceToWord[cur] = word;
        }
        
        for(auto &diff : differences)
            if(diff.second == 1)
                return differenceToWord[diff.first];
            
        return "";
    }
};
//https://leetcode.com/problems/odd-string-difference/